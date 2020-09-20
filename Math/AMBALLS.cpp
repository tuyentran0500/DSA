/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << "#" << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 305;
const int mod = 1e9 + 7;
int t;
int group[N], spaces[N], numGroup;
int dp[N][N];
int combination[N][N];
void init(){
	combination[0][0] = 1;
	for(int i=1;i<N;++i){
		for(int j=1;j<i;++j) combination[j][i] = (combination[j][i-1] + combination[j-1][i-1]) % mod;
		combination[0][i] = combination[i][i] = 1;
	}
}
void solve(){
	// dp[i][j] : number of ways to choose i groups and have j bad spaces 
	// (which is two consecutive elements are equal). 
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int x=0;x<numGroup;++x){
		for(int y=0;y<=spaces[x];++y){
			for(int ij=1;ij<=group[x+1];++ij){
				for(int j=0;j <= min(ij,y);++j){
					int i = ij - j;
					int add = (dp[x][y] * combination[i][spaces[x]-y])% mod;
					add *= combination[j][y];	add%=mod;
					add *= combination[ij-1][group[x+1] - 1]; add%mod;
					dp[x+1][y - j+ group[x+1] - ij] += add;
					dp[x+1][y - j+ group[x+1] - ij] %= mod;
				}
			}
		}
	}
	// cout << numGroup << '\n';
	// for(int i=0;i<=numGroup;++i){
	// 	for(int j=0;j<=group[i];++j) cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	cout << dp[numGroup][0] << '\n';
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	init();
	while (t--){
		cin >> numGroup;
		spaces[0] = 1;
		for(int i=1;i<=numGroup;++i) {
			cin >> group[i];
			spaces[i] = spaces[i-1] + group[i];
		}
		// for(int i=1;i<=numGroup;++i) cout << group[i] << ' ' << spaces[i] << '\n';
		solve();
	}
}