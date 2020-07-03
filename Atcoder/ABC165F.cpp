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
const int N = 200005;
const int INF = 2e9;
int a[N];
int ans[N];
vector< vector<int> > G;
int n;
vector<int> dp;
void dfs(int u, int par){
	int pos = lower_bound(dp.begin(), dp.end(), a[u]) - dp.begin();
	int roll = dp[pos];
	dp[pos] = a[u];
	ans[u] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin() - 1;
	for (auto v : G[u]){
		if (v == par) continue;
		dfs(v, u);
	}
	dp[pos] = roll;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	G.assign(n+1, vector<int>());
	dp.assign(n+1, INF); dp[0] = -INF;
	up(i,1,n) cin >> a[i];
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,1);
	up(i,1,n) cout << ans[i] << '\n';
}