/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int logN = 18;
struct edge{
	int color, adj, weight;
	edge(){color = adj = weight = 0;}
	edge( int _adj, int _color,int _weight){
		color = _color;
		adj = _adj;
		weight = _weight;
	}
};
int par[N][logN], level[N];
int sumColor[N], numColor[N];
int ans[N];
pr remark[N];
vector< edge > G[N];
vector< pr > query[N];
int n,q, totalSum = 0;

int lca(int u,int v){
	if (level[u] < level[v]) swap(u,v);
	for(int i=logN-1;i>=0;--i) if (level[u] - (1 << i) >= level[v]) u = par[u][i];
	if (u == v) return u;
	for(int i=logN-1;i>=0;--i) if (par[u][i] != -1 && par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}
void prep(int u,int preU){
	par[u][0] = preU;
	if (preU != -1) level[u] = level[preU] + 1;
	for (auto node : G[u]){ 
		if (node.adj == preU) continue;
		prep(node.adj, u);
	}
}
void solve(int u){
	for(auto cur : query[u]){
		int id = cur.first, w = cur.second;
		ans[id] += w * (totalSum - sumColor[remark[id].first] + numColor[remark[id].first] * remark[id].second);
	}
	for(auto node : G[u]){
		if (node.adj == par[u][0]) continue;
		sumColor[node.color]+= node.weight;
		numColor[node.color]++;
		totalSum += node.weight;
		solve(node.adj);
		sumColor[node.color]-= node.weight;
		numColor[node.color]--;
		totalSum -= node.weight;

	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=1;i<n;++i){
		int u,v,c,d; cin >> u >> v >> c >> d;
		G[u].push_back(edge(v, c, d));
		G[v].push_back(edge(u, c, d));
	}
	// LCA prep
	memset(par, -1, sizeof(par));
	prep(1, -1);
	for(int j=1;j<logN;++j){
		for(int i=1;i<=n;++i){
			if (par[i][j-1] != -1)	par[i][j] = par[par[i][j-1]][j-1];
		}
	}

	for(int i=1;i<=q;++i){
		int u,v, c, d; cin >> c >> d >> u >> v;
		remark[i] = {c, d};
		query[u].push_back({i, 1});
		query[v].push_back({i, 1});
		query[lca(u,v)].push_back({i, -2});
		// cout << u << ' ' << v << ' ' << lca(u, v) << '\n';
	}
	solve(1);
	for(int i=1;i<=q;++i) cout << ans[i] << '\n';
}