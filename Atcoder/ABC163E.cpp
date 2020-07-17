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
const int N = 2005;
pair<int,int> a[N];
long long dp[N][N];
int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int s=1;s<=n;++s){
		for(int i=0;i<=s;++i){
			int j = s - i;
			if (i) dp[i][j] = dp[i-1][j] + 1LL * (a[s].second - i) * a[s].first;
			if (j) dp[i][j] = max(dp[i][j], dp[i][j-1] + 1LL * (n - j + 1  - a[s].second) * a[s].first);
		}
	}
	long long ans = 0;
	for(int i=0;i<=n;++i){
		ans = max(ans, dp[i][n-i]);
	}
	cout << ans;
}