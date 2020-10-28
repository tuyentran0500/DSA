/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 305;
const int mod = 1e9 + 7;
const int div2 = 500000004;
void add(int& u,int v){
	u +=v;
	if (u < 0) u += mod;
	u%=mod;
}
int multi(int u,int v){
	return (1LL * u * v) % mod;
}
int dp[N][N];
int n,m,l;
int C[N][N];
int fact[N];
void init(){
	C[0][0] = 1;
	for(int i=1;i<N;++i){
		C[0][i] = 1;
		for(int j=1;j<=i;++j) C[j][i] = (C[j-1][i-1] + C[j][i-1]) % mod;
	}
	fact[0] = 1;
	for(int i=1;i<N;++i) fact[i] = multi(fact[i-1], i);
}
int solve(int maxSZ){
	memset(dp, 0, sizeof(dp));
	// dp[i][j]: # of ways to build using i nodes, j edges.
	dp[0][0] = 1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=m;++j){
			if (!dp[i][j]) continue;
			// choose the first fixed pivot x.
			//  x is independent
			if (maxSZ >= 1) add(dp[i+1][j], dp[i][j]);
			// choose an path from x.  
			for(int k=2;k<=maxSZ;++k){
				if (i + k > n) break;
				int res = multi(C[k-1][n-i-1], fact[k]);
				res = multi(res, div2);
				add(dp[i+k][j+k-1], multi(dp[i][j], res));
			}
			// choose another nodes and form a cycle with x.
			if (maxSZ >= 2) add(dp[i+2][j+2], multi(dp[i][j],n - i - 1));
			for(int k=3;k<=maxSZ;++k){
				if (i+k > n) break;
				int res = multi(C[k-1][n-i-1], fact[k-1]);
				res = multi(res, div2);
				add(dp[i+k][j+k], multi(dp[i][j], res));
			}
		}
	}
	return dp[n][m];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> l;
	init();
	cout << (solve(l)-solve(l-1) + mod) % mod;
}