/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
vector<int> G[N];
int child[N];
int n;
long long res = 0;
long long ans = 0;
void dfs(int u,int pre){
	child[u] = 1;
	for(auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
		child[u] += child[v];
	}
	ans += child[u];
}
void solve(int u,int pre){
	for(auto v : G[u]){
		if (v == pre) continue;
		int preU = child[u], preV = child[v];
		ans -= (child[u] + child[v]);
		child[u] = preU - preV;
		child[v] = preU;
		ans += (child[u] + child[v]);
		res = max(res, ans);
		solve(v, u);
		ans -= (child[u] + child[v]);
		child[u] = preU;
		child[v] = preV;
		ans += (child[u] + child[v]);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,2,n){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	res = ans;
	solve(1,0);
	cout << res;
}