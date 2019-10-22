#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
#define int long long
const int N = 100005;
const int K = 105;
const int INF = 2e9;
int n,k;
int dp[N][K];
int a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("BLOCKS_IZHO.inp", "r", stdin);
	// freopen("BLOCKS_IZHO.out", "w", stdout);
	cin >> n >> k;
	up(i,1,n) cin >> a[i];
	int curMax = 0;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][1] = 0;
	up(i,1,n)	dp[i][1] = max(dp[i-1][1], a[i]);
	for(int j = 2; j <= k ;++j){
		vector< pair<int,int> > sk;	
		for( int i = j;i <= n;++i){
			int minF = dp[i-1][j-1];
			// first = value
			// second = id
			while (!sk.empty() && a[sk.back().second] <= a[i]){
				minF = min (minF, sk.back().first);
				sk.pop_back();
			}
			dp[i][j] = min(dp[sk.empty() ? 0 : sk.back().second][j], minF + a[i]);
			sk.push_back(pair<int,int> (minF, i));
		}
	}
	cout << dp[n][k];
}