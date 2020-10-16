/*input
 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 505;
const int mod = 1e9 + 7;
int dp[2][N][N];
int n,m;
char a[N][N];
int solve(int x1,int y1,int x2,int y2){
	if (x1 < 0 || x1 > n || x2 < 0 || x2 > n ||
		y1 < 0 || y1 > m || y2 < 0 || y2 > m) return 0;
	int step = x1 - 1 + y1 - 1;
	int &res = dp[step & 1][x1][x2];
	if (res != -1) return res;
	if (x1 > x2 || y1 > y2) return res = 0;
	if (x1 == x2 && y1 == y2) return res = 1;
	if ((x1 == x2 && y1 + 1 == y2) || (y1 == y2 && x1 + 1 == x2)) return res = (a[x1][y1] == a[x2][y2]);
	if (a[x1][y1] != a[x2][y2]) return res = 0;
	res = solve(x1+1,y1,x2-1,y2);
	res += solve(x1+1,y1,x2,y2-1); res%= mod;
	res += solve(x1,y1+1,x2-1,y2); res%= mod;
	res += solve(x1,y1+1,x2,y2-1); res%= mod;
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) up(j,1,m) cin >> a[i][j];
	memset(dp, -1, sizeof(dp));
	for(int step = (m + n - 2)/2; step >=0 ; --step){
		up(i,1,n) up(j,1,n) dp[step&1][i][j] = -1;
		// step, x1, x2: in that order.
		for(int x1 = 1; x1 <= n; ++ x1){
			for(int x2 = x1; x2 <= n; ++ x2){
				int y1 = step - x1 + 2;
				int y2 = n + m - x2 - step;
				solve(x1,y1,x2,y2);
			}
		}
	}
	int step = (n - 1 + m - 1)/2;
	cout << dp[0][1][n] << '\n';
}