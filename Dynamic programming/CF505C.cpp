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
const int STEP = 250;
int dp[N][505], cnt[N];
int n,d;
int solve(int i,int j){
	// j is the last step
	// abs(d - j) <= STEP.

	if (i > 30000 || abs(d - j) > STEP) return 0;
	// cout << i << ' ' << j << '\n';
	if (dp[i][d - j + STEP] != -1) return dp[i][d - j + STEP];
	int res = 0;
	if (j > 1) res = solve(i + j - 1, j - 1);
	res = max(res, max(solve(i + j, j), solve(i + j + 1,j + 1)));
	return dp[i][d - j + STEP] = res + cnt[i];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;
	for(int i=1;i<=n;++i){
		int x; cin >> x;
		cnt[x]++;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(d,d);
}