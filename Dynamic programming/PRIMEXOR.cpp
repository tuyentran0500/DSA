/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 8200;
const int mod = 1e9 + 7;
long long dp[1005][N];
int cnt[N];
int n,t;
int a[N];
bool ok[N];
void eratosen(){
	for(int i=2;i<(1 << 13);++i){
		if (!ok[i]){
			for(int j=i*i;j<(1 << 13);j += i){
				ok[j] = true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	eratosen();
	while (t--){
		cin >> n;
		up(i,3500,4500) cnt[i] = 0;
		up(i,1,n){
			int x; cin >> x;
			cnt[x]++;
		}
		int m = 0;
		up(i,3500, 4500){
			if (cnt[i]) a[++m] = i;
		}
		// up(i,1,m) cout << a[i] << ' ' << cnt[a[i]] << '\n';
		dp[0][0] = 1;
		up(i,1,m){
			up(j,0,N - 1){
				dp[i][j] = 1LL * dp[i-1][j] * (cnt[a[i]]/2 + 1) % mod; 
				dp[i][j] += 1LL * dp[i-1][j ^ a[i]] * ((cnt[a[i]]+1)/2) % mod;
				dp[i][j] %= mod;
			}
		}
		long long ans = 0;
		for(int i=2;i<(1 << 13);++i) if (!ok[i]) {
			ans += dp[m][i];
			ans %= mod;
		}
		cout << ans << '\n';
	}
}