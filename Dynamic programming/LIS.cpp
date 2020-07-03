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
const int N = 30005;
const int INF = 1e9;
int a[N],n;
vector<int> dp;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	dp.assign(n+1, INF); dp[0] = -INF;
	for(int i=1;i<=n;++i){
		int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		dp[pos] = a[i];
	}	
	int ans = 0;
	for (int i=1;i<=n;++i) if (dp[i] != INF) ans = i;
	cout << ans;
}