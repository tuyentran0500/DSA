/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 5005;
const int M = 5;
vector<int> G[N];
int ans[N];
int visited[N];
int edge[N];
int n,m;
bool cycle;
void dfs(int u){
	visited[u] = 1;
	for(auto id : G[u]){ int v = edge[id];
		if (!visited[v]){ // forward edge
			dfs(v);
			ans[id] = 1;
		}
		else {
			if (visited[v] == 2){ // forward edge
				ans[id] = 1;
			}
			else { // detect cycle
				cycle = 1;
				ans[id] = 2;
			}
		}

	}
	visited[u] = 2;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v; cin >> u >> v;
		edge[i] = v;
		G[u].push_back(i);
	}
	for(int i=1;i<=n;++i) if (!visited[i]) dfs(i);
	cout << (cycle ? 2 : 1) << '\n';
	up(i,1,m) cout << ans[i] << ' ';
}