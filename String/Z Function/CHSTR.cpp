/*input
3
5 5
ababa
2
1
3
4
5 1
aaaaa
4
5 4
ababa
2
1
3
4
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
string s;
int t,n,q;
long long c[N][N];
int cnt[N];
long long ans[N];
int z[N];
int cnt1[N];
void Zfunction(string S){
	for(int i=0;i<=S.size()+1;++i) cnt1[i] = z[i] = 0;
	z[0] = S.size();
	cnt1[S.size()]++;
	int l = 0, r = 0;
	for(int i = 1;i<S.size();++i){
		if (i <= r)
			z[i] = min(z[i-l], r-i+1);
		while (i + z[i] < S.size() && S[z[i]] == S[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
		cnt1[z[i]]++;
	}
	for(int i=S.size();i>=1;--i) {
		cnt1[i] += cnt1[i+1];
		cnt[cnt1[i]]++;
	}
}
void solve(){
	memset(cnt, 0, sizeof(cnt));
	memset(ans, 0, sizeof(ans));
	for(int i=0;i<n;++i) Zfunction(s.substr(i,n-i));
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j) ans[i] = (ans[i] + 1LL * (cnt[j]-cnt[j+1]) * c[i][j]) % mod;
	}
}
void precal(){
	c[0][0] = 1;
	for(int i=1;i<N;++i){
		c[0][i] = c[i][i] = 1;
		for(int j=1;j<i;++j) c[j][i] = (c[j][i-1] + c[j-1][i-1]) % mod;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	precal();
	while (t--){
		cin >> n >> q >> s;
		solve();
		for(int i=1;i<=q;++i){
			int x; cin >> x;
			cout << ans[min(x, n+1)] << '\n';
		}
	}
}