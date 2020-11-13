/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 300005;
const int mod = 998244353;
#define ll long long
ll fact[N]; // stupid mistake again :((
// template 
void init(){
	fact[0] = 1;
	up(i,1,N-1) fact[i] = (1LL * fact[i-1] * i) % mod;
}
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
ll C(int k,int n){
	ll num = fact[n];
	ll den = (fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
int a[N],n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	n*=2;
	up(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	init();
	ll s = 0;
	for(int i=1;i<=n;++i) s += (i <=n/2 ? -1LL : 1LL) * a[i];
	s %= mod;
	cout << (1LL * s * C(n/2, n)) % mod; 
}