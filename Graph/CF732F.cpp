/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 400005;
vector< pr > G[N];
int low[N], num[N];
int numSCC, scc[N], sz[N];
int cnt = 0;
int n,m;
vector<int> visited;
bool ok[N];
pr edge[N];
void dfs(int u,int pre){
	low[u] = num[u] = ++cnt;
	visited.push_back(u);
	for(auto node : G[u]){ int v = node.first;
		if (v == pre) continue;
		if (num[v]){
			low[u] = min(low[u], num[v]);
		}
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == num[u]) { // there is a loop
		numSCC++;
		while (true){
			int v = visited.back(); visited.pop_back();
			low[v] = num[v] = INT_MAX;
			sz[numSCC]++;
			scc[v] = numSCC;
			if (v == u) break;
		}
	}
}
void newDFS(int u){
	low[u] = num[u] = ++cnt;
	for(auto node : G[u]){
		int id = node.second, v = node.first;
		if (!ok[id]){
			edge[id] = {u, v};
			if (num[v]) low[u] = min(low[u], num[v]);
			else {
				newDFS(v);
				low[u] = min(low[v], low[u]);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v; cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(1, 0);
	int root = 1;
	for(int i=1;i<=n;++i) if (sz[scc[i]] > sz[scc[root]]) root = i;
	memset(num, 0, sizeof(num));
	memset(low, 0, sizeof(low));
	newDFS(root);
	cout << sz[scc[root]] << '\n';
	for(int i=1;i<=m;++i) cout << edge[i].first << ' ' << edge[i].second << '\n';
}