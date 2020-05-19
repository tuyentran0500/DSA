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
const int N = 100005;
int dp[2][N];
int p[N];
int trace[N][30];
string s,t;
int n,m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	n = s.size();
	m = t.size();
	t = t + " ";
	for(int i=1;i<m;++i){
		int j = p[i-1];
		while (j && t[j] != t[i]) j = p[j-1];
		if (t[j] == t[i]) j++;
		p[i] = j;
	}
	for(int i=0;i<=m;++i){
		for(char c = 'a';c <= 'z'; ++c){
			if (t[i] == c)  trace[i][c - 'a'] = i + 1;
			else {
				if (!i) continue;
				int j = p[i-1];
				trace[i][c - 'a'] = trace[j][c-'a'];
			}

		}
	}
	for(int i = 0;i<=m;++i) dp[0][i] = INT_MIN;
	dp[0][0] = 0;
	if (s[0] == t[0] || s[0] == '?') dp[0][1] = (m == 1);
	for(int i=0;i<n-1;++i){
		for(int j=0;j<=m;++j) dp[((i+1)&1)][j] = INT_MIN;
		for(int j=0;j<=m;++j){
			if (dp[i&1][j] == INT_MIN) continue;
			int l = (s[i+1] == '?' ? 0 : s[i+1]-'a'), r = (s[i+1] == '?' ? 'z'-'a' : s[i+1]-'a');
			while (l <= r){
				int nxt = trace[j][l];
				dp[(i+1)&1][nxt] = max(dp[(i+1)&1][nxt], dp[i&1][j] + (nxt == m));
				l++;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=m;++i) ans = max(ans, dp[(n-1) & 1][i]); 
	cout << ans;
}
