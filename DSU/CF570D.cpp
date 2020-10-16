/*input
7 2
1 1 2 3 3 3
aaacaab
3 3
1 3
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 500005;
map<int,int> cnt[N];
int n,m;
vector<int> G[N];
vector<pr> query[N];
int ans[N];
int lvl[N];
char c[N];
void dfs(int u){
	cnt[u][lvl[u]] = 1 << (c[u] - 'a');
	for(auto v : G[u]){
		lvl[v] = lvl[u] + 1;
		dfs(v);
		if (cnt[u].size() < cnt[v].size()){
			cnt[u].swap(cnt[v]);
		}
		for(auto it : cnt[v]){
			cnt[u][it.first] ^= it.second;
		}
	}
	for(auto it : query[u]){
		int h = it.first, id = it.second;
		ans[id] = __builtin_popcount(cnt[u][h]);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=2;i<=n;++i){
		int u; cin >> u;
		G[u].push_back(i);
	}
	up(i,1,n) cin >> c[i];
	for(int i=1;i<=m;++i){
		int u,d; cin >> u >> d;
		query[u].push_back({d-1,i});
	}
	dfs(1);
	// up(i,1,m) cout << ans[i] << '\n';
	up(i,1,m) cout << (ans[i] <= 1 ? "Yes" : "No")<< '\n';
}