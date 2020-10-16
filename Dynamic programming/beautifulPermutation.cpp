/*input
1
4
1 2 2 1
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;
long long dp[N][N];
int a[N];
int n,q;
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
long long inv(long long num, long long den){
	return (num * power(den, mod - 2)) % mod;
}
void add(long long &x, long long y){
	x += y;
	x %= mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> q;
	long long div2 = inv(1,2);
	while (q--){
		cin >> n;
		up(i,1,n) cin >> a[i];
		sort(a+1,a+1+n);
		up(i,0,n) up(j,0,n+1) dp[i][j] = 0;
		dp[1][0] = 1;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=i+1;++j){
				if (a[i] == a[i-1]) dp[i][j] = dp[i][j] * div2 % mod;
				if (j) add(dp[i+1][j-1], dp[i][j] * j);
				if (a[i] == a[i+1]) add(dp[i+1][j+1], 2*dp[i][j]);
				add(dp[i+1][j], dp[i][j] * max(i+1 - j - (a[i] == a[i+1]) * 2, 0));
			}
		}
		// cout << dp[3][0] << '\n';
		// up(i,1,n){up(j,0,i) cout << dp[i][j] << ' '; cout << '\n';}
		cout << dp[n][0] << '\n';
	}
}