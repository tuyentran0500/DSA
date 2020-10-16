/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 205;
const int mod = 1e9 + 7;
int dp[N][N][N][2];
int p[N];
int n,m;
string s;
void kmp(){
	p[0] = 0;
	for(int i=1;i<s.size();++i){
		int j = p[i-1];
		while (j && s[j] != s[i]) j = p[j-1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
}
void add(int &a,int b){
	a += b;
	a %= mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	kmp();
	n *= 2;
	m = s.size();
	dp[0][0][0][0] = 1;
	for(int i=0;i<n;++i){
		// memset
		// up(j,0,m) up(cur,0,n) up(state,0,1) dp[(i+1) & 1][j][cur][state] = 0;
		for(int j=0;j<m;++j){
			for(int cur=0;cur<=i;++cur){
				for(int state = 0;state <= 1;++state){
					if (!dp[i][j][cur][state]) continue;
					int nxtj = j;
					// add '('
					while (nxtj && s[nxtj] != '(') nxtj = p[nxtj-1];
					if (s[nxtj] == '(') nxtj++;
					add(dp[(i+1)][nxtj][cur + 1][state | (nxtj == m)],dp[i][j][cur][state]);

					if (!cur) continue;
					nxtj = j; 
					while (nxtj && s[nxtj] != ')') nxtj = p[nxtj-1];
					if (s[nxtj] == ')') nxtj++;
					add(dp[(i+1)][nxtj][cur - 1][state | (nxtj == m)],dp[i][j][cur][state]);
				}
			}
		}
		for(int cur=0;cur <=i;++cur){
				if (!dp[i][m][cur][1]) continue;
				int nxtj = m;	
				// add '('
				while (nxtj && s[nxtj] != '(') nxtj = p[nxtj-1];
				if (s[nxtj] == '(') nxtj++;
				add(dp[(i+1)][nxtj][cur + 1][1],dp[i][m][cur][1]);
				if (!cur) continue;
				nxtj = m; 
				while (nxtj && s[nxtj] != ')') nxtj = p[nxtj-1];
				if (s[nxtj] == ')') nxtj++;
				add(dp[(i+1)][nxtj][cur - 1][1], dp[i][m][cur][1]);
		}
	}
	int ans = 0;
	for(int j=0;j<=m;++j) add(ans, dp[n][j][0][1]);
	cout << ans;
}