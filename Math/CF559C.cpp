/*input

*/
// https://codeforces.com/contest/559/problem/C
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 2005;
const int maxH = 2e5 + 5;
const int mod = 1e9 + 7;
ll dp[N];
pr point[N];
ll fact[maxH];
int h,w,n;
void init(){
	fact[0] = 1;
	up(i,1,maxH-1) fact[i] = (fact[i-1] * i) % mod;
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
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w >> n;
	up(i,1,n) cin >> point[i].first >> point[i].second;
	point[++n].first = h; point[n].second = w;
	sort(point+1, point+1+n);
	init();
	up(i,1,n){
		int hv = point[i].first, wv = point[i].second;
		dp[i] = C(hv-1,hv + wv - 2);
		for(int j=1;j<i;++j) {
			if (point[j].second <= point[i].second) {// total inside
				hv = point[i].first  - point[j].first, wv = point[i].second - point[j].second;
				ll prev = (dp[j] * C(hv, hv + wv)) % mod;
				dp[i] = (dp[i] - prev + 1LL*mod*mod) % mod;
			}
		}
	}
	// up(i,1,n) cout << dp[i] << ' ';
	cout << dp[n];
}