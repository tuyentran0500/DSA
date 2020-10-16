/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
vector<int> G[N];
map<int,int> cnt[N];
int n, color[N], mx[N];
long long ans[N];
void dfs(int u,int pre){
	cnt[u][color[u]] = 1;
	mx[u] = 1;
	ans[u] = color[u];
	for(auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
		if (cnt[u].size() < cnt[v].size()){
			cnt[u].swap(cnt[v]);
			mx[u] = mx[v];
			ans[u] = ans[v];
		}
		for(auto it : cnt[v]){
			int cur = cnt[u][it.first] += it.second;
			if (mx[u] < cur){
				mx[u] = cur;
				ans[u] = 0;
			}
			if (mx[u] == cur){
				ans[u] += it.first;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> color[i];
	up(i,2,n){
		int u,v; cin >> u >> v; 
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	up(i,1,n) cout << ans[i] << ' ';
}