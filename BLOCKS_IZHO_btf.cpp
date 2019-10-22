#include <iostream>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 1e5 + 5;
const int K = 105;
const int INF = 2e9;
int a[N],n,k;
int dp[N][K];
int main(){
	freopen("BLOCKS_IZHO.inp", "r", stdin);
	// freopen("BLOCKS_IZHO.ans", "w", stdout);

	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	int curMax = 0; 
	up(i,1,n){
		curMax = max(curMax, a[i]);
		dp[i][1] = curMax;
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<= min(i, k);++j){
			curMax = a[i];
			dp[i][j] = INF;
			for(int k = i-1;k>=1;--k){
				curMax = max(curMax, a[k]);
				dp[i][j] = min(dp[i][j], dp[k][j-1] + curMax);
			}
		}
	}
	cout << dp[n][k];
}