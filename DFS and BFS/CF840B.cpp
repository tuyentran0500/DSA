/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 300005;
int d[N];
int c[N];
vector<pr> G[N];
bool ok[N];
bool edge[N];
int n,m;
bool possible(){
	int s = 0, firstD = 0;
	up(i,1,n) {
		if (d[i] == -1) firstD = i;
		else {
			s += (d[i] != G[i].size() % 2);
		}
	}
	if (firstD){
		if (s & 1) d[firstD] = !(G[firstD].size() % 2);
		up(i,1,n) if (d[i] == -1) d[i] = G[i].size() % 2; 
		return true;
	}
	return s % 2 == 0;
}
int edgeSize;
void dfs(int u){
	c[u] = (d[u] != G[u].size() % 2);
	ok[u] = 1;
	for (auto node : G[u]){	
		int id = node.second, v = node.first;
		if (ok[v]) continue;
		dfs(v);
		if (c[v]){
			if (c[u]) c[u] = c[v] = 0;
			else c[u] = 1, c[v] = 0;
			// cout << u << ' ' << v << '\n';
			edge[id] = 1;
			edgeSize--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) {
		cin >> d[i];
	}
	up(i,1,m){
		int u,v;	cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	if (possible()){
		// up(i,1,n) cout << d[i] << ' '; cout << '\n';
		edgeSize = m;
		dfs(1);
		cout << edgeSize << '\n';
		up(i,1,m) if (!edge[i]) cout << i << '\n';
	}
	else cout << -1;

}