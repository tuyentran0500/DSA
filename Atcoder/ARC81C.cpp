/*input
abcdefghijklmnopqrstuvwxyz
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int INF = 1e9;
string s;
int nxt[N][30];
int dp[N];
int n;
void init(){
	n = s.size();
	for(int i=0;i<='z'-'a';++i) nxt[n][i] = n;
	for (int i=n-1;i>=0;--i){
		for (char c = 'a' ; c<= 'z'; ++c){
			if (c == s[i]) nxt[i][c - 'a'] = i;
			else nxt[i][c-'a'] = nxt[i+1][c-'a'];
		}
	}
}
string solve(){
	dp[n] = 1;
	for(int i=n-1;i>=0;--i){
		dp[i] = INF;
		for(int j=0;j<='z'-'a';++j){
			dp[i] = min(dp[nxt[i][j]+1] + 1, dp[i]);
		}
	}
	int curPos = 0;
	string ans;
	while (curPos < n){
		for(int j=0;j<='z'-'a';++j){
			if (dp[curPos] == dp[nxt[curPos][j] + 1] + 1){
				ans += (j + 'a');
				curPos = nxt[curPos][j] + 1;
				break;
			}
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// for(char c = 'a'; c<= 'z';++c) cout << c; cout << '\n';
	cin >> s;
	init();
	cout << solve();
}