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
const int N = 3005; 
const int mod = 998244353;
int dp[N][N];
int a[N],n,s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	up(i,1,n) cin >> a[i];
	dp[0][0] = 1;
	for (int i=1;i<=n;++i){
		dp[i][0] = i+1;
		for (int j=1;j<a[i];++j) dp[i][j] = dp[i-1][j];
		dp[i][a[i]] = i + dp[i-1][a[i]];
		for (int j=a[i]+1;j<=s;++j){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i]]) % mod;
		}
	}
	long long ans = 0;
	for(int i=1;i<=n;++i) {
		if (a[i] > s) continue;
		ans += 1LL * dp[i-1][s - a[i]] * (n - i + 1);
		// cout << dp[i-1][s - a[i]] * (n - i + 1) << ' ';
		ans %= mod;
	}
	cout << ans;
}