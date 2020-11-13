/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 505;
const int mod = 998244353;
int multi(int a, int b){
	return (1LL * a * b) % mod;
}
void add(int& u,int v){
	u = (u + v) % mod;
}
int dp[N][N], c[N];
int n,m;
int solve(int l, int r){
	if (l >= r) return dp[l][r] = 1;
	if (dp[l][r] != -1) return dp[l][r];
	int& res = dp[l][r];
	res = 0;
	int pos = l;
	for(int i=l;i<=r;++i){
		if (c[i] < c[pos]) pos = i;
	}
	for(int a=l;a <= pos; ++a){
		add(res,  multi(solve(l,a-1), solve(a, pos-1)));
	}
	int cur = 0;
	for(int b=pos; b <= r; ++b){
		add(cur, multi(solve(pos+1, b), solve(b + 1, r)));
	}
	res = multi(res, cur);
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> c[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(1, n);
}