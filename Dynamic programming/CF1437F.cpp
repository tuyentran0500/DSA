/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 5005;
const int mod = 998244353;
int dp[N][N], sum[N][N];
int a[N], n;
int p[N];
int add(int u,int v){
	int ans = (u + v) % mod;
	if (ans < 0) ans += mod;
	return ans;
}
int multi(int u,int v){	
	return (1LL * u * v) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	sort(a,a+n);
	int cnt = 0;
	for(int i=0;i<n;++i) {
		while (a[cnt] * 2 <= a[i]) cnt++;
		p[i] = cnt; // number of j such that a[i] >= 2 * a[j].  
	}
	for(int i=0;i<n;++i) {
		dp[i][1] = 1;
		sum[i+1][1] = i + 1;
	}
	// call dp[i][j] is the number of way to choose j numbers 
	// and i-th is the last happy number.  
	for(int j=2;j<=n;++j){
		for(int i=0;i<n;++i){
			if (p[i] + 1 >= j){
				dp[i][j] = multi(dp[i][j-1], add(p[i] + 2, -j));
				dp[i][j] = add(dp[i][j], sum[p[i]][j-1]);
			}
			else dp[i][j] = 0;
			sum[i+1][j] = add(sum[i][j], dp[i][j]);
		}
	}
	cout << dp[n-1][n];
}