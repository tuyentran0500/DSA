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
int a[N],n;
int group[N], spaces[N], numGroup = 0;
int dp[N][N];
int combination[N][N];
int fact[N];
void init(){
	fact[0] = 1;
	up(i,1,N-1) fact[i] = (fact[i-1] * i) % mod;
}
void solve(){
	combination[0][0] = 1;
	for(int i=1;i<N;++i){
		for(int j=1;j<i;++j) combination[j][i] = (combination[j][i-1] + combination[j-1][i-1]) % mod;
		combination[0][i] = combination[i][i] = 1;
	}
	// cout << combination[1][2] << '\n';
	for(int i=1;i<=n;++i){
		for(int j=2;j*j <= a[i];++j){
			while (a[i] % (j*j) == 0) a[i]/=(j*j);
		}
	}
	sort(a+1,a+1+n);
	int cnt = 1, numGroup = 0;
	spaces[0] = 1;
	for(int i=2;i<=n;++i){
		if (a[i] != a[i-1]){
			group[++numGroup] = cnt;
			spaces[numGroup] = spaces[numGroup-1] + group[numGroup];
			cnt = 1;
		}
		else cnt++;
	}
	if (cnt){
		group[++numGroup] = cnt;
		spaces[numGroup] = spaces[numGroup-1] + group[numGroup];
	}
	// dp[i][j] : number of ways to choose i groups and have j bad spaces 
	// (which is two consecutive elements are equal). 
	dp[0][0] = 1;
	for(int x=0;x<numGroup;++x){
		for(int y=0;y<=spaces[x];++y){
			for(int ij=1;ij<=group[x+1];++ij){
				for(int j=0;j <= min(ij,y);++j){
					int i = ij - j;
					int add = (dp[x][y] * combination[i][spaces[x]-y])% mod;
					add *= combination[j][y];	add%=mod;
					add *= fact[group[x+1]]; add%=mod; // permutation on the way

					add *= combination[ij-1][group[x+1] - 1]; add%mod; 
					dp[x+1][y - j+ group[x+1] - ij] += add;
					dp[x+1][y - j+ group[x+1] - ij] %= mod;
				}
			}
		}
	}
	cout << dp[numGroup][0];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;	
	up(i,1,n) cin >> a[i];
	init();
	solve();
}