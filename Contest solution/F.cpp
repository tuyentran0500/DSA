/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
#define int long long
using namespace std;
const int N  = 55;
ll dp[N][N][N];
int n, m, k;
ll w[N];
const int mod = 998244353;
ll power(ll x, ll n){
	ll ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
ll inv(ll num, ll den){
	return (num * power(den, mod - 2)) % mod;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i){
		cin >> w[i];
		w[n+1] += w[i];
	}
	for(int i=1;i<=n;++i) w[i] = inv(w[i], w[n+1]);
	dp[0][0][0] = 1;
	for(int i=1;i<=n;++i) dp[i][0][0] = 1;
	// dp[i][j][z] : first i items, choose j different items, and picked z.
	for(int z=1;z<=k;++z){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				// not pick i
				dp[i][j][z] = dp[i-1][j][z];
				// pick i.
				dp[i][j][z] += (1LL * dp[i][j][z-1] * w[i]) % mod; dp[i][j][z] %= mod;
				dp[i][j][z] += (1LL * dp[i-1][j-1][z-1] * w[i]) % mod; dp[i][j][z] %= mod;
			}
		}
	}
	ll ans = 0;
	// cout << dp[2][1][1] << ' ' << inv(1, 9) << '\n';
	cout << dp[n][m][k];
}