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
string s,t;
int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	n = s.size();
	for(int i=1;i<t.size();++i){
		int j = p[i-1];
		while (j & s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	for(int i=1;i<=t.size();++i) dp[0][i] = INT_MIN;
	for(int i=0;i<s.size();++i){
		for(int j=0;j<=t.size();++j){
			if (dp[i&1][j] == INT_MIN) continue;
			if (j == t.size() || s[i] != t[j]){
				int z = j;
				while (z > 0 && t[z] != s[i]) z = p[z-1];
				if (t[z] == s[i]) z++;
				dp[(i+1) & 1][z] = max(dp[(i+1)&1][z], dp[i][j]);
			}
			else if (s[i] == t[j]) 
				dp[(i+1) & 1][j+1] = max(dp[(i+1) & 1][j+1], dp[i][j] + (j +1 == t.size()));
		}
	}
	int ans = 0;
	for(int i=0;i<=t.size();++i) ans = max(ans, dp[n & 1][i]);
}
