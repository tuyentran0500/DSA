/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
// observation: You can prove that we only need to go back to at most 1 cell before coming back.
// -->     v>-
// <-v --->|||
// v.>     >.>
const long long INF = 1e17;
long long dp[N][3];
int a[N][3],n;
void upd(long long&x, long long y) {
	x = max(x,y);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(j,0,2) up(i,1,n) cin >> a[i][j];
	up(i,0,n) up(j,0,2) dp[i][j] = -INF;
	dp[0][0] = 0;
	for(int i=0;i<n;++i){
		// do not go back.
		upd(dp[i+1][0], dp[i][0] + a[i+1][0]);
		upd(dp[i+1][1], dp[i][0] + a[i+1][0] + a[i+1][1]);
		upd(dp[i+1][2], dp[i][0] + a[i+1][0] + a[i+1][1] + a[i+1][2]);

		upd(dp[i+1][0], dp[i][1] + a[i+1][0] + a[i+1][1]);
		upd(dp[i+1][1], dp[i][1] + a[i+1][1]);
		upd(dp[i+1][2], dp[i][1] + a[i+1][2] + a[i+1][1]);

		upd(dp[i+1][0], dp[i][2] + a[i+1][2] + a[i+1][1] + a[i+1][0]);
		upd(dp[i+1][1], dp[i][2] + a[i+1][2] + a[i+1][1]);
		upd(dp[i+1][2], dp[i][2] + a[i+1][2]);
		if (i == n-1) continue;
		// go back at most one cell.

		upd(dp[i+2][2], dp[i][0] + a[i+1][0] + a[i+2][0] + a[i+1][1] + a[i+2][1] + a[i+1][2] + a[i+2][2]);
		upd(dp[i+2][0], dp[i][2] + a[i+1][2] + a[i+2][2] + a[i+1][1] + a[i+2][1] + a[i+1][0] + a[i+2][0]);
	}
	cout << dp[n][2];
}