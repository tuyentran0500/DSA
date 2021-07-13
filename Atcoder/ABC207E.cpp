#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 3005;
const int mod = 1e9 + 7;
void add(int& a, int b){
	a = (a + b) % mod;
}
int dp[N][N], cnt[N][N];
long long a[N];
int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	// cnt[i][j] is the sum of all dp[k][j] such that sum[k] = a[1] + a[2] + ... + a[k] % (j + 1) = i.
	cnt[0][0] = 1;
	up(i,1,n){
		up(j,1,n) dp[i][j] = cnt[a[i] % j][j-1];
		up(j,1,n) add(cnt[a[i] % (j+1)][j], dp[i][j]);
	}
	int ans = 0;
	up(i,1,n) add(ans, dp[n][i]);
	cout << ans;
}