/*input

*/
// https://www.hackerrank.com/challenges/construct-the-array/problem
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
long dp[N][3];
int n,k,x;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> x;
	dp[1][0] = dp[1][1] = 1;
	dp[1][2] = (x == 1);
	for(int i=2;i<=n;++i){
		dp[i][0] = (k-1) * dp[i-1][0] % mod;
		dp[i][1] = (dp[i-1][0] - dp[i-1][1] + mod) % mod;
		dp[i][2] = (dp[i-1][0] - dp[i-1][2] + mod) % mod;
	}
	cout << dp[n][2];
}