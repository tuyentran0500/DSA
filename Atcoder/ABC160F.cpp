/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define long long long
using namespace std;
const int N = 200005;
const int mod = 1e9 + 7;
vector<int> G[N];
int children[N], pchildren[N];
long ans[N], dp[N], pDp[N];
long fact[N];
int n;
void init(){
	up(i,1,n) dp[i] = children[i] = 1;
	fact[0] = 1;
	for(int i=1;i<=n;++i) fact[i] = (fact[i-1] * i * 1LL) % mod;
}
long power(long x, long n){
	long ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
long inv(long num, long den){
	return (num * power(den, mod - 2)) % mod;
}
long C(int k,int n){
	int num = fact[n];
	int den = (fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
void precal(int u, int par){
	for (auto v: G[u]){
		if (v == par) continue;
		precal(v, u);
		children[u] += children[v];
	}
	int remaider = children[u] - 1;
	for(auto v : G[u]){
		if (v == par) continue;
		// cout << children[v] << ' ' << remaider << '\n';
		long cur = (1LL * dp[v] * C(children[v], remaider)) % mod;
		dp[u] = (dp[u] * cur) % mod;
		remaider -= children[v];
	}
}
void rollback(int u,int v){
	pDp[u] = dp[u]; pDp[v] = dp[v];
	pchildren[u] = children[u]; pchildren[v] = children[v];
}
void dfs(int u, int par){
	ans[u] = dp[u];
	for (auto v: G[u]){
		if (v == par) continue;
		rollback(u,v);
		dp[u] = inv(dp[u], (dp[v] * C(children[v], children[u]-1)) % mod);
		children[u] -= children[v];
		children[v] += children[u];
		long mul = (dp[u] * C(children[u], children[v] - 1)) % mod;
		dp[v] = (dp[v] * mul) % mod;
		dfs(v, u);
		dp[u] = pDp[u]; dp[v] = pDp[v];
		children[u] = pchildren[u]; children[v] = pchildren[v];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init();
	precal(1,0);
	// solve
	dfs(1, 0);
	for(int i=1;i<=n;++i) cout << ans[i] << '\n';
}