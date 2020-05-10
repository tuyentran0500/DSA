#include <stdio.h>
#include <iostream> 
#include <vector>
const int N = 10005;
using namespace std;
int u,v, cnt;
int low[N], num[N];
vector < vector<int> > G;
bool ok[N];
int khop, cau, n, m;
void dfs(int u,int pre){
    low[u] = num[u] = ++cnt;
    int chid = 0;
    for(int i=0;i<G[u].size();++i){ int v = G[u][i]; if (v == pre) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
            else {
                chid++;
                dfs(v,u); low[u] = min(low[u], low[v]);
                if (low[v] >= num[v])  cau++;
                if (low[v] >= num[u] && u != pre) ok[u] = 1; 
            }
        }
        if (u == pre && chid >= 2) ok[u] = 1;
    }
int main(){
    //freopen ("test.inp","r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    G.assign (n+1, vector<int>());
    for(int i=1;i<=m;++i) {
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;++i) if (!num[i]) dfs(i,i);
    for(int i=1;i<=n;++i) khop += ok[i];
    cout << khop << ' ' << cau;