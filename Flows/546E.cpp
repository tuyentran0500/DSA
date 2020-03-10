#include <iostream>
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 205;
const int INF = 1e9;
int n,m;
int a[N], b[N];
int c[N][N], f[N][N], s,t;
int d[N], ptr[N];
bool bfs(){
	queue<int> q;
	up(i,s,t) d[i] = INF;
	q.push(s); d[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for(int v = 0; v <= 2*n + 1;++v){
			if (d[v] > d[u] + 1 && c[u][v] > f[u][v] /*residual network*/){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return (d[t] != INF);
}
int dfs(int u,int cur_flow){
	if (!cur_flow || u == t) return cur_flow;
	for(int& v = ptr[u]; v <= t; ++v){
		if (d[v] != d[u] + 1) continue;
		int nxt_flow = dfs(v, min(cur_flow, c[u][v] - f[u][v]));
		if (nxt_flow){
			f[u][v] += nxt_flow;
			f[v][u] -= nxt_flow;
			return nxt_flow;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    s = 0, t = 2*n + 1;
    int sumA = 0, sumB = 0;
    up(i,1,n) {
    	cin >> a[i];
    	c[s][i] = a[i];
    	sumA += a[i];
    }
    up(i,1,n){
    	cin >> b[i];
    	c[i+n][t] = b[i];
    	sumB += b[i];
    }
    up(i,1,n) c[i][i+n] = INF;
    up(i,1,m){
    	int u,v; cin >> u >> v;
    	c[u][v+n] = INF;
    	c[v][u+n] = INF;
    }
    int ans = 0;
    while (bfs()){
    	up(i,s,t) ptr[i] = 0;
    	while (int augment_path = dfs(s,INF)) ans += augment_path;
    }
    if (ans != sumA || ans != sumB) cout << "NO";
    else {
    	cout << "YES\n";
    	up(i,1,n){
    		up(j,1,n) cout << f[i][j+n] << ' ';
    		cout << '\n';
    	}
    }
}