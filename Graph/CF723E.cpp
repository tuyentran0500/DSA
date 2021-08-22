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
int t,n,m;
const int N  = 205;
vector< vector<int> > G;
int id[N], deg[N], visited[N];
bool isReal[N][N];
int prep(){
	cin >> n >> m;
	G.assign(n+1, vector<int>());
	memset(deg, 0, sizeof(deg));
	memset(id, 0, sizeof(id));
	memset(isReal, 0, sizeof(isReal));
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<m;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		isReal[u][v] = isReal[v][u] = 1;
		deg[u]++;
		deg[v]++;
	}
	int prevNode = -1;
	int res = 0;
	for(int u=1;u<=n;++u) if (deg[u] & 1){
		if (prevNode != -1){
			G[u].push_back(prevNode);
			G[prevNode].push_back(u);
			deg[u]++;
			deg[prevNode]++;
		}
		prevNode = u;
	}
	else res++;
	return res;
}
void solve(){
	vector<int> edgeList;
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if (visited[i]) continue;
		visited[i] = 1;
		edgeList.push_back(i);
		while (edgeList.size()){
			int u = edgeList.back(); 
			if (deg[u]) {
				ans.push_back(u);
				edgeList.pop_back();
				visited[u] = 1;
			}
			else {
				int v = G[u][id[u]++];
				edgeList.push_back(v);
				deg[u]--;
				deg[v]--;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto u : ans) cout << u << ' '; cout << '\n'; 
	for(int i=0;i<ans.size();++i){
		int u = ans[i], v = ans[(i+1) % ans.size()];
		if (isReal[u][v]){
			cout << u << ' ' << v << '\n';
			isReal[u][v] = isReal[v][u] = 0;
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		int ans = prep();
		cout << ans << '\n';
		solve();
	}	
}