/*input

*/
// https://www.hackerrank.com/challenges/fair-cut/problem
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 3005;
const long long INF = 1e18;
long long dp[N][N];
long long a[N];
int n,k;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	int m = n - k;
	up(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	up(i,0,n) up(j,0,n) dp[i][j] = INF;
	dp[0][0] = 0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,k);++j){
			if (j) dp[i][j] = dp[i-1][j-1] + 1LL * (2*(i-j) - m) * a[i];
			dp[i][j] = min(dp[i][j], 
						   dp[i-1][j] + 1LL * (2*j - k) * a[i]);
		}
	}
	cout << dp[n][k] << '\n';
}