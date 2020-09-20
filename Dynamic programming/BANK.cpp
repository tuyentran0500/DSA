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
const int N = 20;
int a[N], b[N];
int n,m;
pr dp[1 << N]; // dp[mask] = (i, j): have already payed i-th bill, and the current bills, have already payed j.
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;++i) cin >> a[i];
	for(int j=0;j<m;++j) cin >> b[j];
	for(int i=1;i<(1 << m);++i) dp[i] = {-1, -1};
	dp[0] = {0,0};
	bool ans = false;
	for(int mask = 0; mask < (1 << m); ++mask){
		if (dp[mask] == pr(-1,-1)) continue;
		if (dp[mask] == pr(n, 0)) ans = 1;
		int pos = dp[mask].first, bill = dp[mask].second;
		for(int i=0;i<m;++i) {
			if (bits(mask, i)) continue;
			if (bill + b[i] > a[pos]) continue;
			if (bill + b[i] == a[pos]) dp[mask|(1 << i)] = {pos + 1, 0};
			else dp[mask|(1 << i)] = {pos, bill + b[i]};
		}
	}
	cout << (ans ? "YES" : "NO");
}