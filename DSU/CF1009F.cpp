/*input

*/
// https://codeforces.com/contest/1009/problem/F
// DSU on tree
// IN the merge process, we can prove that it's worth O(N).  
// You can expand the problem even further
/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1000005;
map<int,int> cnt[N];
vector<int> G[N];
pair<int,int> ans[N];
int lvl[N],n;
// Why merge only take O(n) memory?.  
void dfs(int u,int pre){
	cnt[u][lvl[u]] = 1;
	ans[u] = {1, -lvl[u]};
	for (auto v : G[u]){
		if (v == pre) continue;
		lvl[v] = lvl[u] + 1;
		dfs(v, u);
		if (cnt[u].size() < cnt[v].size()){
			cnt[u].swap(cnt[v]);
			ans[u] = ans[v];
		}
		for(auto it : cnt[v]){
			int cur = cnt[u][it.first] += it.second;
			ans[u] = max(ans[u], {cur, -it.first});
		}
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
	dfs(1, 0);
	// up(i,1,n) cout << ans[i].first << ' ' << -ans[i].second << '\n';
	for(int i=1;i<=n;++i) cout << -ans[i].second - lvl[i] << '\n';
}