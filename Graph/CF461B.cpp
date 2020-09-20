/*input

*/
// https://codeforces.com/contest/461/problem/B
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
int n;
vector<int> G[N];
long long dp[N][2];
int c[N];
void dfs(int u,int pre){
	for(int i=0;i<2;++i) dp[u][i] = (c[u] == i);
	for (auto v : G[u]){
		if (v == pre) continue;
		int prevDp[2];
		prevDp[0] = dp[u][0];
		prevDp[1] = dp[u][1];
		dfs(v, u);
		dp[u][0] = dp[u][1] = 0;
		// include v.
		dp[u][0] += prevDp[0] * dp[v][0] % mod;
		dp[u][1] += prevDp[0] * dp[v][1] % mod;
		dp[u][1] += prevDp[1] * dp[v][0] % mod;
		dp[u][1] %= mod;
		// not include v
		dp[u][0] += prevDp[0] * dp[v][1] % mod;
		dp[u][0] %= mod;
		dp[u][1] += prevDp[1] * dp[v][1] % mod;
		dp[u][1] %= mod;
	}
}
int main(){
	cin >> n;
	for(int u=2;u<=n;++u){
		int v; cin >> v; ++v;
		G[u].push_back(v);
		G[v].push_back(u);
	} 
	up(i,1,n) cin >> c[i];
	dfs(1, 0);
	cout << dp[1][1];
}