/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
const int N = 5005, mod = 1e9 + 7;
long long h[2][N],hb;
long long base[N];
int dp[N][N];
using namespace std;
int n;
string a,b;
void init(){
	cin >> a;
	n = a.size();
	base[0] = 1;
	up(i,1,n) base[i] = (base[i-1] * 30) % mod;  
	for(int i=0;i<a.size();++i){
		h[0][i+1] = (h[0][i] * 30 + a[i] - 'a' + 1) % mod; 
		h[1][i+1] = (h[1][i] * 30 + a[n-i-1] - 'a' + 1) % mod;
	}
}
long long get(int t, int l,int r){
	if (t){
		l = n + 1 - l;
		r = n + 1 - r;
		swap(l,r);
	}
	return (h[t][r] - h[t][l-1]*base[r-l+1] + 1LL*mod*mod) % mod;
}
int ans[N];
void solve(){
	up(i,1,n) dp[i][i] = 1;
	ans[1] = n;
	for(int j=2;j<=n;++j){
		for(int i=1;i+j-1<=n;++i){
			if (get(0,i,i+j-1) == get(1,i,i+j-1)) {
				dp[i][i+j-1] = dp[i][i+j/2-1] + 1;
				ans[dp[i][i+j-1]]++;
			}
		}
	}
	for(int i=n-1;i>=1;--i) ans[i] += ans[i+1];
	up(i,1,n) cout << ans[i] << ' ';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	solve();
}