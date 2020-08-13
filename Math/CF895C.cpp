/*input

*/
// https://codeforces.com/contest/895/problem/C
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 75;
const int PRIME_NUM = 19;
const int mod =  1e9 + 7;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int dp[N][1 << 19];
int maskNum[N];
int cnt[N];
int n;
long long base[100005];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	// init();
	base[0] = 1;
	for (int i=1;i<=n;++i){
		int u; cin >> u;	cnt[u]++;
		base[i] = base[i-1] * 2 % mod;
	}
	// Prepare maskNum
	for(int i=1;i<=70;++i){
		int curVal = i;
		for(int j=0;j<PRIME_NUM;++j){
			if (prime[j] > curVal) break;
			int cnt = 0;
			while (curVal % prime[j] == 0) curVal/=prime[j], cnt = !cnt;
			if (cnt) maskNum[i] += (1 << j);
		}
	}
	dp[0][0] = 1;
	for (int i=1;i<=70;++i){
		for (int mask = 0; mask < (1 << PRIME_NUM); ++mask){
			if (!cnt[i]) dp[i][mask] = dp[i-1][mask];
			else {
				// cout << pVal << '\n';
				dp[i][mask] = 1LL * (dp[i-1][mask] + dp[i-1][mask ^ maskNum[i]]) * base[cnt[i] - 1] % mod;
			}
		}
	}
	cout << (dp[70][0] + mod - 1) % mod;
}
