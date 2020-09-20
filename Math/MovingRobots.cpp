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
const int N = 105;
double dp[10][10][N];
double ans[N][N];
int n;
double solve(int startX,int startY,int endX,int endY){
	up(i,1,8) up(j,1,8) up(k,0,n) dp[i][j][k] = 0.0;
	dp[startX][startY][0] = 1;
	for(int k=0;k<n;++k){
		for(int i=1;i<=8;++i){
			for(int j=1;j<=8;++j){
				double dir = (i > 1) + (i < 8) + (j > 1) + (j < 8);
				if (i > 1) dp[i-1][j][k+1] += dp[i][j][k]/dir;
				if (i < 8) dp[i+1][j][k+1] += dp[i][j][k]/dir;
				if (j > 1) dp[i][j-1][k+1] += dp[i][j][k]/dir;
				if (j < 8) dp[i][j+1][k+1] += dp[i][j][k]/dir;			
			}
		}
	}
	return dp[endX][endY][n];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,8) up(j,1,8) ans[i][j] = 1;
	up(i,1,8){
		up(j,1,8){
			up(i1,1,8){
				up(j1,1,8){
					// cout << solve(i1,j1,i,j) << '\n';
					ans[i][j] *= (1.0 - solve(i1,j1,i,j));
				}
			}
		}
	}
	double res = 0;
	up(i,1,8) up(j,1,8) res += ans[i][j];
	cout << fixed << setprecision(6) << res;
}