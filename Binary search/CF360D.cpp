/*input

*/
// HSGS Team Selection 2017.  
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 2005;
int dp[N], a[N];
int n,k;
bool f(int d){
	up(i,1,n) dp[i] = i - 1;
	for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if (1LL * abs(a[i] - a[j]) <= 1LL * (j - i) * d) dp[j] = min(dp[j], dp[i] + (j-i-1));
		}
	}
	int ans = n;
	up(i,1,n) ans = min(ans, dp[i] + (n - i));
	return (ans <= k);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) cin >> a[i];
	int l = 0, r = 2e9;
	int ans = 0;
	while (l <= r){
		if (f(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}	
	cout << ans;
}