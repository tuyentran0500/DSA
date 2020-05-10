#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 10005, M = 100005, INF = 1e6;
int n,m;
vector < vector<int> > G;
int low[N], num[N], cnt = 0;
vector<int> ad;
int scc;
void dfs(int u,int pre){
    ad.push_back(u);
    low[u] = num[u] = ++cnt;
    for(int i=0;i<G[u].size();++i){int v = G[u][i]; if (v == pre) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
            else {
                dfs(v,u); low[u] = min(low[u], low[v]);
            }
    }
    if (low[u] == num[u]){
        scc++;
        while (ad.back() != u){
            low[ad.back()] = num[ad.back()] = INF;
            ad.pop_back();
        }
        low[u] = num[ad.back()] = INF;  ad.pop_back();
    }
}
int main(){
    //freopen ("test.inp","r", stdin);
    cin >> n >> m;
    G.assign (n+1, vector<int>());
    for(int i=1;i<=m;++i){
        int u,v; cin >> u >> v;
        G[u].push_back(v); 
    }
    for(int i=1;i<=n;++i) if (!num[i]) dfs(i,i);
    cout << scc;
}
 