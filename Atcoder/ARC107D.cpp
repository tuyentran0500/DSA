/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 3005;
const int mod = 998244353;
int dp[N*2][N];
int sum[N*2][N];
void add(int& u,int v){
	u = (u + v) % mod;
}
int n,k;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	dp[0][0] = 1;
	sum[0][0] = 1;
	// sum = i, have j choices. i <= j.
	for(int j=1;j<=n;++j){
		for(int i=2*n;i>=1;--i){
			if (i > j) dp[i][j] = 0;
			else dp[i][j] = sum[2*i][j];
			add(sum[i][j], dp[i][j]);
			if (i >= 2) add(sum[i][j], sum[i-2][j-1]);
		}
	}
	cout << dp[k][n] << '\n';
}