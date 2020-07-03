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
const int N = 2000005;
const long long mod = 1e9 + 7;
long long fact[N];
int k,n;
string s;
void init(){
	fact[0] = 1;
	up(i,1,n+k) fact[i] = (fact[i-1] * i) % mod;
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
	int num = fact[n];
	int den = (fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k >> s;
	n = s.size();
	init();
	long long ans = 0;
	for(int i=0;i<=k;++i){
		long long cur = (power(25, k-i) * power(26, i)) % mod;
		ans += (C(k-i, n+k-i-1) * cur) % mod;
		ans %= mod;
	}
	cout << ans;
}