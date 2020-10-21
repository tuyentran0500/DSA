/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 20;
const int mod = 1e9 + 7;
ll f[N], dp[1 << N], n, s;
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
void add(ll &u, ll v){
	u = (u + v) % mod;
}
void sub(ll &u, ll v){
	u = (u - v + mod) % mod;
}
ll multi(ll u, ll v){
	return ((u % mod) * (v % mod)) % mod;
}
ll C(ll k,ll n){
	ll num = 1;
	for(ll i=1;i<=k;++i) num = multi(num, n - i + 1);
	ll den = 1;
	for(ll i=2;i<=k;++i) den = multi(den, i);
	return inv(num, den);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for(int i=0;i<n;++i) cin >> f[i];
	ll ans = C(n-1, n + s - 1);
	// dp[mask] is the number of ways to construct sum s by choosing some x_i > f_i.  
	for(int mask=1;mask < (1 << n);++mask){
		ll sum = s, cnt = 0;
		for(int i=0;i<n;++i) if (bits(mask, i)) {
			cnt++;
			sum -= (f[i]+1); 
		}
		if (sum < 0) continue;
		dp[mask] = C(n-1, n + sum - 1);
		if (cnt & 1) sub(ans, dp[mask]);
		else add(ans, dp[mask]);
		// cout << mask << ' ' << dp[mask] << '\n';
	}
	cout << ans;
}