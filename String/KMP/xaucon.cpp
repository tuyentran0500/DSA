/*input

*/
// http://lqdoj.edu.vn/problem/xaucon
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 5005;
string s;
int q,n;
int dp[N][N];
vector<int> KMP(string s){
	vector<int> p(s.size(), 0);
	vector<int> ans(s.size(), 0);
	for(int i=1;i<s.size();++i){
		int j = p[i-1];
		while (j && s[j] != s[i]) j = p[j-1];
		if (s[i] == s[j]) j++;
		p[i] = j;
		if (!p[i]) ans[i] = 0;
		else ans[i] = ans[p[i] - 1] + 1;
	}
	return ans;
}
int get(int l,int r){
	return dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> q;
	n = s.size();
	for(int i=0;i<n;++i){
		vector<int> kmpString = KMP(s.substr(i));
		for(int j=0;j<kmpString.size();++j) dp[i+1][i+j+1] = kmpString[j];
	}	
	// up(i,1,n) {up(j,1,n) cout << dp[i][j]; cout << '\n';} cout << '\n';
	up(i,1,n) up(j,1,n) dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
	// up(i,1,n) {up(j,1,n) cout << dp[i][j]; cout << '\n';}
	while (q--){
		int l,r; cin >> l >> r;
		cout << get(l,r) << '\n';
	}
}
