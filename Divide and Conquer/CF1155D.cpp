/*input

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 300005;
ll dp[N][3];
int c[3], n, x;
int a[N];

void maximize(ll& u, ll v){
	u = max(u, v);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	for(int i=1;i<=n;++i) cin >> a[i];
	c[0] = c[2] = 1; 
	c[1] = x;
	ll ans = 0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j){
			maximize(dp[i][j], 1LL * a[i] * c[j]);
			maximize(dp[i][j], 1LL * a[i] * c[j] + dp[i-1][j]);
			if (j) maximize(dp[i][j], dp[i-1][j-1] + 1LL * a[i] * c[j]);
			maximize(ans, dp[i][j]);
		}
	}
	// cout << dp[3][1] << '\n';
	cout << ans;

}