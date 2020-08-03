/*input

*/
// https://codeforces.com/contest/780/problem/E  	
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
vector<int> G[N];
vector<int> ans[N];
bool ok[N];
int n,k,m;
int pset[N];
void init(){ for(int i=1;i<=n;++i) pset[i] = i; }
int finds(int u){
	return (pset[u] == u ? u : pset[u] = finds(pset[u]));
}
bool same(int u,int v){
	return finds(u) == finds(v);
}
void join(int u,int v){
	pset[finds(u)] =  finds(v);
}
vector<int> eulerTour;
void dfs(int u,int par){
	eulerTour.push_back(u);
	for(auto v : G[u]){
		if (v == par) continue;
		dfs(v, u);
		eulerTour.push_back(u);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >>  k;
	init();
	for(int i=1;i<=m;++i){
		int u,v; cin >> u >> v;
		if (!same(u,v)) {
			join(u,v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	dfs(1, 0);
	int cnt = 0;
	n*=2;
	int maxSize = (n/k) + (n % k != 0);
	// for (auto u : eulerTour){
	// 	cout << u << ' ';
	// }
	cout << '\n';
 	for(auto u : eulerTour){
		if (ans[cnt].size() == maxSize) cnt++;	
		if (!ans[cnt].size() && ok[u]) continue;
 		ans[cnt].push_back(u);
 		ok[u] = 1;
	}
	for(int i=0;i<k;++i){
		if (!ans[i].size()){
			cout << 1 << ' ' << 1 << '\n';
		} 
		else {
			cout << ans[i].size() << ' ';
			for(auto u : ans[i]) cout << u << ' ';
			cout << '\n';
		}
	}
}