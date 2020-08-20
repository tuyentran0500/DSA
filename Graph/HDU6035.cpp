/*input

*/
// https://codeforces.com/gym/102253/problem/C
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 200005;
int block[N], ans[N], color[N];
vector< vector<int> > G;
int n, delta = 0;
int t;
void dfs(int u,int par){
	int preBlock = block[color[u]] + delta;
	for (auto v : G[u]){
		if (v == par) continue;
		int preVal = block[color[u]] + delta;
		dfs(v, u);
		int curVal = block[color[u]] + delta;
		ans[color[u]] += (curVal - preVal)*(curVal - preVal - 1)/2;
	}
	delta++;
	block[color[u]] = preBlock - delta;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("solve.inp","r", stdin);
	while(t++, cin >> n){
		for(int i=1;i<=n;++i) cin >> color[i];
		G.assign(n+1, vector<int>());
		delta = 0;
		for(int i=1;i<=n;++i) block[i] = ans[i] = 0;
		for(int i=1;i<n;++i){
			int u,v; cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int res = 0;
		for(int i=1;i<=n;++i){
			block[i] += n;
			ans[i] += block[i]*(block[i]-1)/2;
			ans[i] = n*(n-1)/2 - ans[i];
			res += ans[i];
		}
		// for(int i=1;i<=n;++i) cout << ans[i] << ' ';
		cout << "Case #" << t << ": " <<  res << '\n';
	}
}