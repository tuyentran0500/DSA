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
const int N = 2505;
int dp[N][N];
int ans[N];
int n,m;
string s, p;
void precal(){
	n = s.size();
	m = p.size();
	memset(dp, -1, sizeof (dp));
	dp[0][0] = 1;
	if (s[0] == p[0]) dp[0][1] = 1;
	for(int i=1;i<n;++i){
		dp[i][0] = i+1;
		for(int j=1;j<=i+1;++j){
			if (s[i] == p[(j + m - 1) % m] && dp[i-1][j-1] != -1)
				dp[i][j] = dp[i-1][j-1] + 1;
			if (dp[i-1][j] != -1)
				dp[i][j] = max(dp[i][j], dp[i-1][j] + (j % m == 0));
		}
	}
	// for(int i=0;i<n;++i){
	// 	for(int j=0;j<=i+1;++j) cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	for(int i=1;i<=n;++i) {
		if (dp[n-1][i] == -1) continue;
		// cout << dp[n-1][i] << ' ';
		ans[dp[n-1][i]] = max(ans[dp[n-1][i]], i);
	}
	// ans[i]: số lần lặp đạt được khi có i kí tự.
	for(int i=n;i>=0;--i) ans[i] = max(ans[i], ans[i+1]);
	// down(i,n,1) cout << ans[i] << ' ';
	for(int i=n;i>=0;--i){
		cout << min(i, ans[i])/m << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> p;
	precal();
}