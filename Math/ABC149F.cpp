/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define ll long long
#define pr pair<ll,ll>
using namespace std;
const int N = 200005;
const ll mod = 1e9 + 7;
int a[N], child[N],n;
vector<int> G[N];
// template 
ll power(ll x, ll n){
	ll ans = 1;
	for (int i=0;i<30;++i){
		if (bits(n, i)){
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
	}
	return ans;
}
ll inv(ll num,ll den){
	return (num * power(den, mod - 2)) % mod;
}
ll ans = 0;
void dfs(int u,int pre){
	child[u] = 1;
	for (auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
		child[u] += child[v];
		ans += (power(2, child[v]) - 1LL) * (power(2, n - child[v]) - 1LL);
		ans %= mod;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<n;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans = (power(2, n) - 1LL * n * power(2, n-1) - 1LL) % mod;
	dfs(1, 0);
	cout << inv(ans, power(2, n));
}