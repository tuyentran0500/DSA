#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 1005;
const int INF = 1e9;
int s,t,c[N][N], f[N][N];
int ptr[N];
int d[N];
int n,m;
bool bfs(){
	queue<int> q;
	up(i,1,n) d[i] = INF;
	q.push(s); d[s] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v=1;v<=n;++v){
			if (d[v] > d[u] + 1 && c[u][v] > f[u][v]) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return (d[t] != INF);
}
int dfs(int u,int cur_flow){
	if (!cur_flow || u == t) return cur_flow;
	for(int& v = ptr[u]; v <= n; ++v){
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
	cin >> n >> m >> s >> t;
	up(i,1,m){
		int u,v,ct; cin >> u >> v >> ct;
		c[u][v] = ct; 
	}
	int ans = 0;
	while (bfs()){
		up(i,1,n) ptr[i] = 0;
		while (int cur = dfs(s,INF)) ans += cur;
	}
	cout << ans;
}