/*input
5 6
2 3
2 1
1 3
1 4
4 5
5 1
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 30005;
vector<int> G[N];
bool ok[N];
int n,m;
vector<int> ans;
void dfs(int u){
	ok[u] = 1;
	for(auto v : G[u]){
		if (!ok[v]){
			dfs(v);
		}
	}
	ans.push_back(u);

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v; cin >> u >> v;
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i) if (!ok[i]) dfs(i);
	reverse(ans.begin(), ans.end());
	for(int i=0;i<ans.size();++i) cout << ans[i] << ' ';
}