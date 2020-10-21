/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const long long INF = -1e18;
long long dp[N][2][3][2];
// (i, +/-, (i + j) % 3, check sneaky case)  
int a[N], n;
void maximize(long long& a, long long b){
	a = max(a,b);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n) up(j,0,1) up(sum,0,2) up(ok,0,1) dp[i][j][sum][ok] = INF;
	if (n == 1) {
		cout << a[n] << '\n';
		return 0;
	}
	dp[1][0][2][0] = -a[1]; // 0 is minus
	dp[1][1][1][0] = a[1];
	for(int i=1;i<n;++i){
		for(int isPositive = 0; isPositive <= 1; ++isPositive){
			for(int sum = 0; sum < 3; ++sum){
				for(int ok = 0; ok <= 1; ++ok){
					if (dp[i][isPositive][sum][ok] == INF) continue;
					// choose the next number is minus.
					maximize(dp[i+1][0][(sum + 2) % 3][ok | !isPositive],
							 dp[i][isPositive][sum][ok] - a[i+1]);
					// choose the next number is positive
					maximize(dp[i+1][1][(sum + 1) % 3][ok | isPositive],
							 dp[i][isPositive][sum][ok] + a[i+1]); 
				}
			}
		}
	}
	cout << max(dp[n][0][1][1], dp[n][1][1][1]);
}