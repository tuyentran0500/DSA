/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define pr pair<int,int>
using namespace std;
// https://cses.fi/problemset/task/1691
// Find an euler cycle
const int N = 100005;
set<int> G[N];
int deg[N];
int n,m;
int main(){
	cin >> n >> m;
	up(i,1,m){
		int u,v; cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;++i){
		if (deg[i] & 1) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	vector<int> edgeList;
	edgeList.push_back(1);
	vector<int> ans;
	while(edgeList.size()){
		int u = edgeList.back();
		if (!deg[u]){
			ans.push_back(u);
			edgeList.pop_back();
		}
		else {
			for(auto v : G[u]) {
				G[u].erase(v);
				G[v].erase(u);
				edgeList.push_back(v);
				deg[u]--;
				deg[v]--;
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() != m+1) cout << "IMPOSSIBLE\n";
	for(auto v : ans) cout << v << ' ';
}