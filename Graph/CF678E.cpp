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
const int N = 18;
double dp[N][1 << N], a[N][N];
int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,0,n-1) up(j,0,n-1) cin >> a[i][j];
	for(int mask = 1;mask < (1 << n);++mask){
		for(int i=0;i<n;++i){
			if (!bits(mask, i)) continue;
			int nmask = mask - (1 << i);
			if (!nmask){
				dp[i][mask] = 1.0;
				continue;
			}
			int cnt = 0;
			for(int j=0;j<n;++j) if (bits(nmask, j)){
				dp[i][mask] += dp[j][nmask] * a[i][j];
				// cnt++;
			}
			for(int j=0;j<n;++j) if (bits(nmask, j)){
				dp[i][mask] += dp[i][mask - (1 << j)] * a[i][j];
				// cnt++;
			}
			dp[i][mask]/= __builtin_popcount(mask);
		}
	} 
	up(mask,1,(1 << n) - 1){
		up(i,0,n-1) cout << dp[i][mask] << ' ';
		cout << '\n';
	}
	// cout << dp[0][3] << '\n';
	cout << dp[0][(1 << n) - 1];
}