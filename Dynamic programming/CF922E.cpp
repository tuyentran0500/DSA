/*input
4 1000000000 10000000 35000000 
1 2 4 5
1000000000 500000000 250000000  200000000 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 10005;
const int INF = -1e18;
int dp[2][N];
int a[N], c[N], num[N];
int w,b,x;
int numBirds,n;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> w >> b >> x;
	for(int i=1;i<=n;++i){
		cin >> num[i];
		for(int j=1;j<=num[i];++j){
			a[++numBirds] = i;
		}
	}
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	up(i,0,numBirds) dp[1][i] = INF;
	dp[1][0] = w;
	dp[1][1] = (w - c[a[1]] < 0 ? INF : min(w + b, w - c[a[1]]));
	for(int i=2;i<=numBirds;++i){
		for(int j=0;j<=numBirds;++j) dp[i & 1][j] = INF;
		for(int j=0;j<=i;++j){
			if (j && dp[(i-1) & 1][j-1] != INF) {
				dp[i&1][j] = min (w + b * j, dp[(i-1) & 1][j-1] - c[a[i]] + (a[i] != a[i-1] ? x : 0));
			}
			dp[i & 1][j] = max(dp[i & 1][j], min(w + b * j, dp[(i-1) & 1][j] + (a[i] != a[i-1] ? x : 0)));
			if (dp[i & 1][j] < 0) dp[i & 1][j] = INF;
		}
	}
	
	for(int i=numBirds;i>=0;--i) if (dp[numBirds & 1][i] != INF){
		cout << i;
		return 0;
	}

}