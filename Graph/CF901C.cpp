/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 300005;
vector<int> G[N];
// DSU
int mx[N], mn[N];
ll f[N], sum[N];
int n,m,q;

int par[N], sz[N];
void init(){
	up(i,1,n) par[i] = i;
}
int finds(int u){
	return (par[u] == u ? u : par[u] = finds(par[u]));
}
void unions(int u,int v){
	par[finds(u)] = finds(v);
}
int cnt = 0;
int low[N], num[N];
// find loop edges
vector<pr> lEdge;
void dfs(int u,int pre){
	low[u] = num[u] = ++cnt;
	for(auto v : G[u]){
		if (v == pre) continue;
		if (num[v]){
			low[u] = min(low[u], num[v]);
			lEdge.push_back({u, v});
		}
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] != num[v]) lEdge.push_back({u,v});
		}	
	}
}

ll get(int l,int r){
	int pos = upper_bound(f+1, f+1+n, r) - f;
	if (pos > r) return sum[r] - sum[l-1];
	if (pos < l) return 1LL * (r - l + 1) * (r - l + 2)/2;
	return (sum[pos - 1] - sum[l-1]) + 1LL*(r - pos + 1)*(r - pos + 2)/2; 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	init();
	up(i,1,m){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	up(u,1,n) if (!num[u]) dfs(u, 0);
	for(auto node : lEdge){
		unions(node.first, node.second);
	}
	// find minVal, maxVal of the loop
	for(int i=1;i<=n;++i){
		int root = finds(i);
		if (!mn[root]) mn[root] = i;
		mx[root] = i;
		sz[root]++;
		f[i] = n+1;
	}

	for(int i=1;i<=n;++i){
		if (sz[i] > 1){
			f[mn[i]] = mx[i];
		}
	}
	for(int i=n-1;i>=1;--i) f[i] = min(f[i], f[i+1]);
	for(int i=1;i<=n;++i) {
		sum[i] = sum[i-1] + f[i] - i;
	}
	cin >> q;
	while (q--){
		int l,r; cin >> l >> r;
		// find the first f[i] that >= r.
		cout << get(l,r) << '\n';
	}
}