/*input

*/
// https://atcoder.jp/contests/abc163/tasks/abc163_f
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 200005;
int color[N], block[N];
int ans[N];
int child[N];
int n;
int delta = 0;
vector<int> G[N];
void dfs(int u,int par){
	int preBlock = block[color[u]] + delta;
	for (auto v : G[u]){
		if (v == par) continue;
		int preVal = block[color[u]] + delta; 
		dfs(v, u);
		int newVal = block[color[u]] + delta - preVal;
		ans[color[u]] += newVal * (newVal + 1)/2;	
	}
	delta++;
	block[color[u]] = preBlock - delta;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> color[i];
	}
	for(int i=1;i<n;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	// up(i,1,n) cout << block[i] << ' ';
	for(int i=1;i<=n;++i){
		block[i] += n;
		ans[i] += 1LL * block[i] * (block[i] + 1)/2;
		ans[i] = n*(n+1)/2 - ans[i];
	}
	for(int i=1;i<=n;++i) cout << ans[i] << '\n';
}