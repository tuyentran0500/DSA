/*input

*/
// https://www.spoj.com/problems/BADXOR/  
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2005;
const long long mod = 100000007;
const int logA = 20;
int n,m,t;
int basis[N], sz;
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<logA;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
void insertVector(int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		}
		mask^=basis[i];
	}
}
long long checkVector(int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			// basis[i] = mask;
			// sz++;
			return 0;
		}
		mask^=basis[i];
	}
	return power(2, n - sz);
}
void init(){
	for(int i=0;i<logA;++i) basis[i] = 0; sz = 0;
}
int a[N], b[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	up(iTest,1,t){
		cin >> n >> m;
		init();
		up(i,1,n) {
			cin >> a[i];
			insertVector(a[i]);
		}
		// cout << n << ' ' << sz << '\n';
		long long ans = 0;
		up(i,1,m){
			cin >> b[i];
			ans = (ans  + checkVector(b[i])) % mod;
		}
		// cout << ans << '\n';
		ans = (power(2, n) - ans + mod) % mod;
		cout << "Case " << iTest << ": " <<ans << '\n';
	}
}