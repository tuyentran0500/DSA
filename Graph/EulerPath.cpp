/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
// https://cses.fi/problemset/task/1693
// Find an euler Path
const int N = 100005;
vector<int> G[N], P[N];
int deg[N];
int n,m;
int id[N];
bool isEulerPath(){
	if (deg[1] % 2 == 0 || deg[n] % 2 == 0) return false;
	up(i,2,n-1) if (deg[i] % 2) return false;
	return true;
}
void solve(){
	vector<int> edgeList;
	vector<int> ans;
	edgeList.push_back(1);
	while (edgeList.size()){
		int u = edgeList.back(); 
		if (id[u] == G[u].size()) {
			ans.push_back(u);
			edgeList.pop_back();
		}
		else {
			int v = G[u][id[u]++];
			edgeList.push_back(v);
			deg[u]++;
			deg[v]--;
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() != m + 1) {
		cout << "IMPOSSIBLE";
		return;
	}
	for(auto v : ans) cout << v << ' ';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int u,v; cin >> u >> v;
		deg[u]--;
		deg[v]++;
		G[u].push_back(v);
	} 
	if (isEulerPath()) solve();
	else cout << "IMPOSSIBLE";
}