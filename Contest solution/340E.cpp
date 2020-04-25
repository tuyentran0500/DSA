#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << "debug" << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;
int a[N];
bool ok[N];
long long dp[N][N];
int n;
int freepos, fixedpos;
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n) if (a[i] != -1)	ok[a[i]] = 1;
	up(i,1,n) 
		if (a[i] == -1){
			if (ok[i]) freepos++;
			else fixedpos++;
		}
	long long fact = 1;
	dp[0][0] = 1;
	up(i,1,n) {
		fact = (fact * 1ll * i) % mod;
		dp[i][0] = fact; 
	}
	up(i,0,n) dp[i][1] = (dp[i][0] * i) % mod;
	for(int j=2;j<=n;++j)
		for(int i=0;i<=n+1;++i){
			dp[i][j] = (dp[i][j-1] * i + dp[i+1][j-2] * (j-1)) % mod;
	}
	cout << dp[freepos][fixedpos];
}