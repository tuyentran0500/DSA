/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 10005;
vector<pr> E[N];
bool isPrime(int n){
	for(int i=2;i*i<=n;++i){
		if (n % i != 0) return false;
	}
	return (n != 1);
}
int dp1[N], mod1 = 1e18 + 9;
int dp2[N], mod2 = 1e18 + 17;
int n,q;
void add(int v){
	for(int i=N-v-1;i>=0;--i) {
		dp1[i+v] += dp1[i];
		dp2[i+v] += dp2[i];
		if (dp1[i+v] >= mod1) dp1[i+v] -= mod1; 
		if (dp2[i+v] >= mod2) dp2[i+v] -= mod2; 
	}
}
void del(int v){
	for(int i=v;i<N;++i) {
		dp1[i] -= dp1[i - v];
		dp2[i] -= dp2[i - v];
		if (dp1[i] < 0) dp1[i] += mod1;
		if (dp2[i] < 0) dp2[i] += mod2;
	}
}
bool f[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=q;++i){
		int l,r,v; cin >> l >> r >> v;
		E[l].push_back({v, 1});
		E[r+1].push_back({v, -1});
	}
	dp1[0] = dp2[0] = 1;
	for(int i=1;i<=n;++i){
		for(auto node : E[i]) {
			if (node.second == 1) add(node.first);
			else del(node.first);
		}
		for(int j=1;j<=n;++j) if (dp1[j] && dp2[j]) f[j] = 1;
	}
	vector<int> ans;
	for(int i=1;i<=n;++i) if (f[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for(auto v : ans) cout << v << ' ';
}