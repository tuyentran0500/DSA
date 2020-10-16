/*input
 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long 
using namespace std;
const int N = 2005;
const ll mod = 1e9 + 7;
ll dp[N][N][2];
ll sum[N][N][2], rock[N][N];
int L[N][N], U[N][N];
int n,m;
ll get(int x1,int y1,int x2, int y2,ll s[N][N]){
	return (s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) up(j,1,m){
		char c; cin >> c;
		rock[i][j] = (c == 'R');
		rock[i][j] += rock[i-1][j] + rock[i][j-1] - rock[i-1][j-1];
	}
	// 0: go right
	// 1: go down
	for(int i=2;i<=n;++i) {
		sum[i][1][1] = dp[i][1][1] = (get(1,1,n,1,rock) <= n - i), L[i][1] = 1;
		// sum[1] --> sum down
 
	}
	for(int j=2;j<=m;++j) {
		// sum[0] --> sum right
		sum[1][j][0] = dp[1][j][0] = (get(1,1,1,m,rock) <= m - j), U[1][j] = 1;
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			// dp[i][j][0] = sum(dp[i][j'][1]) and sum(j', n) <= n - j.
			int maxL = L[i][j-1];
			while (maxL < j && get(i,maxL+1,i,m,rock) > m - j) maxL++;
			L[i][j] = maxL;
			dp[i][j][0] = (sum[i][j-1][1] - sum[i][maxL-1][1] + mod) % mod;
			int maxU = U[i-1][j];
			while (maxU < i && get(maxU+1,j,n,j,rock) > n - i) maxU++;
			U[i][j] = maxU;
			dp[i][j][1] = (sum[i-1][j][0] - sum[maxU-1][j][0] + mod) % mod;
			sum[i][j][0] = (sum[i-1][j][0] + dp[i][j][0]) % mod;
			sum[i][j][1] = (sum[i][j-1][1] + dp[i][j][1]) % mod; 
		}
	}
	if (n == 1 && m == 1) cout << !rock[1][1];
	else cout << (dp[n][m][0] + dp[n][m][1]) % mod;
 
}