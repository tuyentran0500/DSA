/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define int ll
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 1005;
const int maxVal = 1e5;
int a[N], n,k;
ll dp[N][N], pref[N][N];
int l[N];
ll solve(int val){
	up(i,0,n) up(j,0,k) dp[i][j] = pref[i][j] = 0;
	l[1] = 0;
	for(int i=2;i<=n;++i) {
		l[i] = l[i-1];
		while (l[i] < i-1 && a[l[i]+1] + val <= a[i]) l[i]++;
	}
	// up(i,1,n) cout << l[i] << ' '; cout << '\n';
	for(int i=1;i<=n;++i){
		dp[i][1] = 1;
		pref[i][1] = pref[i-1][1] + 1;
		for(int cnt=2;cnt<=k;++cnt){
			dp[i][cnt] = pref[l[i]][cnt-1];
			pref[i][cnt] = (pref[i-1][cnt] + dp[i][cnt]) % mod;
		}
	}
	int res = 0;
	up(i,1,n) res = (res + dp[i][k]) % mod;
	// cout << res << '\n';
	return res;
}
signed main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);	
	ll res = 0;
	for(int val = 1; (k-1) * val <= maxVal; ++val) res = (res + solve(val)) % mod;
	cout << res;
}