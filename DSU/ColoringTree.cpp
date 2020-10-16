/*input

*/
// Sol using DSU on tree
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
map<int,bool> cnt[N];
vector<int> G[N];
int c[N], ans[N];
int n,root,m;
void dfs(int u,int pre){
	cnt[u][c[u]] = 1;
	for(auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
		if (cnt[u].size() < cnt[v].size()){
			cnt[u].swap(cnt[v]); // always note this.
		}
		for(auto it : cnt[v]){
			cnt[u][it.first] |= it.second;
		}
	}
	ans[u] = cnt[u].size();
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> root;
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	up(i,1,n) cin >> c[i];
	dfs(root, 0);
	for(int i=1;i<=m;++i){
		int u; cin >> u;
		cout << ans[u] << '\n';
	}
}