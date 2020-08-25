/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
using namespace std;
const int N = 200005;
const int logN = 18;
int d[N], par[N][logN];
int n;
vector<int> G[N];
void dfs(int u,int pre,int depth){
	par[u][0] = pre;
	d[u] = depth;
	for (auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u, depth+1);
	}
}
int lca(int u, int v){
	if (d[u] < d[v]) swap(u, v);
	for(int i=logN-1;i>=0;--i){
		if (d[u] - (1 << i) >= d[v]) u = par[u][i];
	}
	if (u == v) return u;
	for(int i=logN-1;i>=0;--i){
		if (par[u][i] != -1 && par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
int distance(int u,int v){
	return d[u] + d[v] - 2 * d[lca(u,v)];
}
int start_node, end_node;
int bfsD[N];
int bfs(int s){
	queue< int > q;
	memset(bfsD, -1, sizeof(bfsD));
	bfsD[s] = 0;
	q.push(s);
	int ans = 0;
	while (q.size()){
		int u = q.front(); q.pop();
		ans = u;
		for (auto v : G[u]){
			if (bfsD[v] == -1){
				bfsD[v] = bfsD[u] + 1;
				q.push(v);
			}
		}
	}
	return ans;
}
void solve(){
	start_node = bfs(1);
	end_node = bfs(start_node);
	// cout << start_node << ' ' << end_node << '\n';
	for(int i=1;i<=n;++i){
		cout << max(distance(i, start_node), distance(i, end_node)) << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(par, -1, sizeof(par));
	dfs(1, -1, 0);
	// LCA
	for (int j=1;j<logN;++j){
		for(int i=1;i<=n;++i){
			if (par[i][j-1] != -1) par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	solve();
}