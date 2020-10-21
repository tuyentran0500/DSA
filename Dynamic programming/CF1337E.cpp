/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 3005;
const int mod = 998244353;
int n,m;
string s,t;
int dp[N][N];
void add(int &u,int v){
	u = (u + v) % mod;
}
// Call dp[l][r] is the number of way to construct T[l...r] as the prefix. 
int solve(int l,int r){
	int& res = dp[l][r];
	if (res != -1) return res;
	if (l == r){
		return res = ((l > m || t[l] == s[1]) ? 1 : 0);
	}
	res = 0;
	char cur = s[r - l + 1];
	if (l > m || t[l] == cur) add(res, solve(l+1, r));
	if (r > m || t[r] == cur) add(res, solve(l, r-1));
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	n = s.size(); s = "?" + s;
	m = t.size(); t = "?" + t;
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for(int i=m;i<=n;++i) add(ans, solve(1, i));
	cout << (ans * 2) % mod;
}