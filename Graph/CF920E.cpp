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
set<int> G[N];
set<int> unvisited;  
int n,m;
vector<int> ans;
int cc = 0;
// use normal dfs to find the connected components.
// However, to avoid to visit some nodes again, use set unvisited to find the answer
void dfs(int u){
	unvisited.erase(u);
	ans[cc]++;
	int cur = -1;
	while (true){
		set<int>::iterator it = unvisited.upper_bound(cur);
		if (it == unvisited.end()) break;
		cur = *it;
		if (G[u].count(cur)) continue;
		dfs(cur);
	} 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v; cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	up(i,1,n) unvisited.insert(i);
	up(i,1,n){
		if (unvisited.count(i)){
			ans.push_back(0);
			dfs(i);
			cc++;
		}
	}
	sort(ans.begin(), ans.end());
	cout << cc << '\n';
	for(auto v : ans) cout << v << ' ';

}