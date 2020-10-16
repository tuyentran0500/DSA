/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2000006;
const int mod = 1e9 + 7;
long long fact[N];
int n,m;
void init(){
	fact[0] = 1;
	up(i,1,N-1) fact[i] = (fact[i-1] * i) % mod;
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
	init();
	cin >> n >> m;
	long long ans = power(m, n);
	up(i,1,n){
		long long cur = power(m, i) * power(m-1, n - i) % mod;
		cur = (cur * C(i-1,n)) % mod;
		ans += cur;
		ans %= mod;
	}
	cout << ans;
}