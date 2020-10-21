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
int power(int x, int n){
	int ans = 1;
	for(int i=0;i<30;++i){
		if (bits(n, i)) ans = (1LL * ans * x) % mod;
		x = (1LL * x * x) % mod;
	}
	return ans;
}
int inv(int num, int den){
	return (1LL * num * power(den, mod - 2)) % mod;
}
void add(int &u, int v){
	u = (u + v) % mod;
}
int dp[N][N], sum[N][N];
int a[N], cnt[N], n;
signed main(){
	// freopen("solve.inp","r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	cnt[0] = 1;
	for(int i=n;i>=0;--i){
		for(int j=0;j<n;++j) sum[i][j] = sum[i+1][j];
		if (!cnt[i]) continue;
		for(int j=0;j<n;++j){
			dp[i][j] = inv(cnt[i]-1, n - j);
			add(dp[i][j], inv(sum[i+1][j+1], n - j));
			add(sum[i][j], (1LL * dp[i][j] * cnt[i]) % mod);
		}
	}
	cout << dp[0][0] << '\n';
}