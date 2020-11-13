/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
const long long INF = 1e18;
vector<pr> G[N];
vector<int> ds, dt, dpS, dpT;
int s,t,n,m;
void shortestPath(int s,vector<int>& d){
	priority_queue<pr, vector<pr>, greater<pr> > pq;
	d[s] = 0;
	pq.push({0, s}); 
	while (pq.size()){
		int u = pq.top().second, val = pq.top().first; pq.pop();
		if (val != d[u]) continue;
		for(auto node : G[u]){
			int v = node.first, c = node.second;
			if (d[v] > d[u] + c){
				d[v] = d[u] + c;
				pq.push({d[v], v});
			}
		}
	}
}
int multi(int u,int v){
	return (1LL * u * v) % mod;
}
void add(int& u,int v){
	u = (u + v) % mod;
}
void sub(int& u,int v){
	u = (u - v + mod) % mod;
}
void dfs(int s, vector<int> d, vector<int>& dp){
	vector<int> deg;
	vector<int> P[N];
	deg.assign(n+1, 0);
	dp[s] = 1;
	for(int u=1;u<=n;++u){
		for(auto node : G[u]){
			int v = node.first, c = node.second;
			if (d[v] == d[u] + c){
				deg[v]++;
				P[u].push_back(v);
			}
		}
	}
	queue<int> q;
	q.push(s);
	while (q.size()){
		int u = q.front(); q.pop();
		for(auto v : P[u]){
			add(dp[v],dp[u]);
			deg[v]--;
			if (!deg[v]) q.push(v);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	ds.assign(n+1, INF);
	dt.assign(n+1, INF);
	dpS.assign(n+1, 0);
	dpT.assign(n+1, 0);
	for(int i=0;i<m;++i){
		int u,v,c; cin >> u >> v >> c;
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	shortestPath(s,ds);
	shortestPath(t,dt);
	// for(auto v : ds) cout << v << ' '; cout << '\n';
	dfs(t,dt, dpT); // calculate number of way to go from T to S.  
	dfs(s,ds, dpS);
	int ans = multi(dpS[t], dpS[t]);
	for(int i=1;i<=n;++i){
		if (ds[i] == dt[i] && 2 * ds[i] == ds[t]) {
			int cur = multi(dpS[i], dpS[i]);
			cur = multi(cur, dpT[i]);
			cur = multi(cur, dpT[i]);
			sub(ans, cur);
		}
	}
	for(int u=1;u<=n;++u){
		for(auto node : G[u]){
			int v = node.first, c = node.second;
			if (ds[u] < ds[t]/2 && dt[v] < ds[t]/2 && ds[u] + c + dt[v] == ds[t]) {
				int cur = multi(dpS[u], dpS[u]);
				cur = multi(cur, dpT[v]);
				cur = multi(cur, dpT[v]);
				sub(ans, cur); 
			}
		}
	}
	cout << ans;
	// shortest path

}