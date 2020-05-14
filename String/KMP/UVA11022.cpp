/*input
PRATTATTATTIC
GGGGGGGGG
PRIME
BABBABABBABBA
ARPARPARPARPAR
*
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 85;
int dp[N][N];
int n;
string s;
int p[N][N];
int seg[N][N];
void solve(){
	n = s.size();
	for(int i=0;i<n;++i){
		p[i][i] = 0;
		for(int j=i+1;j<n;++j){
			int z = p[i][j-1];
			while (z > 0 && s[z + i] != s[j]) z = p[i][z-1];
			if (s[z + i] == s[j]) z++;
			p[i][j] = z;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int k = (j-i+1) - p[i][j];
			if ((j-i+1) % k == 0) seg[i][j] = k;
			else seg[i][j] = j-i+1;
		}
	}
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) dp[i][j] = INT_MAX;
	for(int i=0;i<n;++i) dp[i][i] = 1;
	for(int len=1;len<n;++len){
		for(int i=0;i+len<n;++i){
			int j = i + len;
			if (seg[i][j] != len + 1) {
				int k = seg[i][j];
				dp[i][j] = dp[i][i+k-1];
			}
			for(int z = i; z < j;++z){
				dp[i][j] = min(dp[i][j], dp[i][z] + dp[z+1][j]);
			}
		}
	}
	cout << dp[0][n-1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> s;
		if (s == "*") break;
		else solve();
	}
}