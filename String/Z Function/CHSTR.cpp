/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
long long h[N];
long long base[N];
int cnt[N*N];
int cntsub[N];
int ans[N];
int c[N][N];
int n,q;
string s;
long long get(int l,int r){
	return ( h[r] - h[l-1] * base[r-l+1] + 1LL*mod*mod) % mod;
}
void init(){
	c[0][0] = 1;
	for(int i=1;i<N;++i){
		c[0][i] = c[i][i] = 1;
		for(int j=1;j<i;++j) c[j][i] = (c[j-1][i-1] + c[j][i-1]) % mod;
 	}	
	base[0] = 1;
	for(int i=1;i<N;++i) base[i] = (base[i-1] * 30) % mod;
}
void solve(){
	for(int i=1;i<=n;++i){
		h[i] = (h[i-1]*30 + s[i-1]-'a'+1) % mod;
	}
	vector<int> substr;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			substr.push_back(get(i,j));
		}
	}
	sort(substr.begin(), substr.end());
	substr.resize(unique(substr.begin(), substr.end()) - substr.begin());
	for(int i=0;i<substr.size();++i) cnt[i] = 0;
	for(int i=1;i<=n;++i) cntsub[i] = ans[i] = 0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int pos = lower_bound(substr.begin(), substr.end(),get(i,j)) - substr.begin();
			cnt[pos]++;
		}
	}
	for(int i=0;i<substr.size();++i){
		cntsub[cnt[i]]++;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ans[i] = (ans[i] + 1LL * c[i][j] * cntsub[j]) % mod;
		}
	}
}
int t;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	init();
	while(t--){
		cin >> n >> q >> s;
		solve();
		for(int i=1;i<=q;++i){
			int k; cin >> k;
			k = min(k, n+1);
			cout << ans[k] << '\n';
		}
	}
}