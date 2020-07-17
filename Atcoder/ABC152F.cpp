/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 55;
long long dp[2][1 << 20];
vector<int> G[N];
pair<int,int> restriction[N];
int n,m;
int level[N], par[N];
int ok[N];
void dfs(int u, int pre){
	par[u] = pre;
	for (auto v : G[u]){
		if (v == pre) continue;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}
void travel(int id,int u, int v){
	while (level[u] > level[v]) {
		ok[u] |= (1 << id);
		u = par[u];
	}
	while (level[v] > level[u]){
		ok[v] |= (1 << id);
		v = par[v];
	}
	while (u != v){
		ok[u] |= (1 << id);
		ok[v] |= (1 << id);
		u = par[u];
		v = par[v];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<n;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cin >> m;
	for(int i=0;i<m;++i){
		int u, v; cin >> u >> v;
		restriction[i] = {u, v};
		travel(i, u, v);
	}
	dp[1][0] = 1;
	for(int i=1;i<n;++i){
		for(int mask = 0; mask < (1 << m);++mask)	dp[(i+1) & 1][mask] = 0;
		for(int mask = 0; mask < (1 << m);++mask){
			if (dp[i & 1][mask]){
				dp[(i+1) & 1][mask] += dp[i & 1][mask];
				dp[(i+1) & 1][mask | ok[i+1]] += dp[i & 1][mask];
			}
		}
	}
	cout << dp[n & 1][(1 << m) - 1];

}