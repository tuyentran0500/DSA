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
const int N = 500005;
const int mod = 1e9 + 7; 
#define long long long
long fact[N];
int n,m;
void init(){
	fact[0] = 1;
	for(int i=1;i<=m;++i) fact[i] = (1LL * fact[i-1] * i) % mod;
}
long power(long x,int n){
	long ans = 1;
	for (int i = 0; i < 31; ++i){
		if (bits(n, i)){
			ans = (1LL * ans * x) % mod;
		}
		x = (1LL * x * x) % mod;
	}
	return ans;
}
long inv(long num, long den){
	return (1LL * num * power(den, mod - 2)) % mod;
}
long C(int k,int n){
	long num = fact[n];
	long den = (1LL * fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
long P(int k,int n){
	return inv(fact[n], fact[n-k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	init();
	long ans = 0;
	for(int k=0;k<=n;++k){
		long cPi = (P(n-k, m-k) * P(n-k, m-k)) % mod;
		cPi = (cPi * P(k, m)) % mod;
		cPi = (cPi * C(k,n)) % mod;
		// cout << cPi << '\n';
		ans = (ans + (k & 1 ? 1LL*mod*mod - cPi : cPi)) % mod;
		// if (ans <= 0) ans = (ans + mod * mod) % mod;
	}
	cout << ans;
}