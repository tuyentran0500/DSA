/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 305;
const int mod = 998244353;
int dp[N][N][N];
int n,k;
string s;
int a[N], m;
int num1;
void add(int& u,int v){
	u = (u + v) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> k;
	n = s.size();
	int cur = 0;
	for (auto v : s){
		if (v == '0'){
			a[++m] = cur;
			cur = 0;
		}
		else {
			cur++;
			num1++;
		}
	}
	if (cur) a[++m] = cur;
	// dp[i][j][move]
	// to segment i-th, have j incomplete '1', and make `move` change.
	k = min(k, num1 - a[1]);
	dp[0][0][0] = 1;
	for(int i=0;i<m;++i){
		for(int j=0;j<=num1;++j){
			for(int move = 0; move <= k; ++move){
				if (!dp[i][j][move]) continue;
				for(int x = -min(a[i+1], j); x <= k - move; ++x){
					add(dp[i+1][j + x][move + max(0, x)], dp[i][j][move]);
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=k;++i) add(ans, dp[m][0][i]);
	cout << ans; 
}