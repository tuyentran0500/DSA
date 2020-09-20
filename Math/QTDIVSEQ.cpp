/*input
8 3 
1 2 3 -1 1 3 1 -1
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define int long long
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
long long fact[N];
void init(){
	fact[0] = 1;
	up(i,1,N-1) fact[i] = (fact[i-1] * 1LL * i) % mod;
}
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
long long inv(long long num, long long den){
	return (num * power(den, mod - 2)) % mod;
}
long long C(int k,int n){
	long long num = fact[n];
	long long den = (fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
long long s[N];
int n, k;
long long dp[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> s[i];
		s[i] += s[i-1];
	}
	if (s[n] == 0) {
		int cnt = 0;
		for(int i=1;i<=n;++i) cnt += (s[i] == 0);
		cout << C(k-1, cnt-1);
		return 0;
	}
	if (s[n] % k) {
		cout << 0;
		return 0;
	}
	long long seg = s[n]/(1LL * k);
	dp[0] = 1;
	for(int i=1;i<=n;++i){
		if (s[i] % seg == 0) {
			dp[s[i]/seg] += dp[s[i]/seg - 1];
			dp[s[i]/seg] %= mod;
		}
	}
	cout << dp[k-1];
}