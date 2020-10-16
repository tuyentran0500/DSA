/*input
 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
#define int ll
using namespace std;
const int K = 10005;
const int M = 55;
const int mod = 1e9 + 7;
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
ll dp[K][M],n;
int k;
ll solve(ll p,ll cnt){
	memset(dp, 0, sizeof(dp));
	dp[0][cnt] = 1;
	up(step,1,k){
		ll sum = 0;
		for(int i=cnt;i>=0;--i) {
			sum += inv(dp[step-1][i], i+1);
			dp[step][i] = sum % mod;
		}
	}
	ll ans = 0;
	for(int i=0;i<=cnt;++i) {
		ans += dp[k][i] * power(p, i) % mod;
		ans %= mod;
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	ll ans = 1;
	for(int i=2;i<=sqrt(n);++i){
		int cnt = 0;
		while (n % i == 0){
			n/=i;
			cnt++;
		}
		if (cnt) {
			ans *= solve(i, cnt), ans %= mod; 
		}
	}
	if (n != 1) ans *= solve(n, 1), ans %= mod;
	cout << ans;
}