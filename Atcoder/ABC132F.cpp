/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define pos(val) (lower_bound(divisor.begin(), divisor.end(), val) - divisor.begin())
using namespace std;
const int M = 100005;
const int K = 105;
const int mod = 1e9 + 7;
int dp[K][M];
int n,k;
int m;
set<int> divisorSet;
vector<int> divisor;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=sqrt(n);++i) {
		divisorSet.insert(i);
		divisorSet.insert(n/i);
	}
	divisor.push_back(0);
	for(auto div : divisorSet){
		divisor.push_back(div);
	}
	m = divisor.size();
	for(int i=0;i<m;++i) dp[0][i] = 1;
	for(int i=1;i<=k;++i){
		for(int j=1;j<m;++j){
			dp[i][j] = (1LL * dp[i-1][pos(n/divisor[j])] * (divisor[j] - divisor[j-1])) % mod;
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
			// cout << dp[i][j] << ' ';
		}
		// cout << '\n';
	}
	cout << dp[k][m-1];

}