#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 21;
bool visited[N];
int color[N];
int n, m;
vector<int> G[N], P[N];
vector<int> vertices;
void dfs(int u, int pre){
	visited[u] = 1;
	vertices.push_back(u);
	for(auto v : G[u]){
		if (v == pre) continue;
		if (!visited[v]){
			dfs(v, u);
		}
	}
}
long long backtrack(int pos){
	long long ans = 0;
	if (pos == vertices.size()) {
		// for(auto v : vertices){
		// 	cout << color[v] <<  ' ';
		// }
		// cout << '\n';
		return 1;
	}
	int u = vertices[pos];
	int mask = 0;
	for(auto v : G[u]){
		if (color[v]) mask |= (1 << color[v]);
	}
	up(c,1,3) if (!bits(mask, c)){
		color[u] = c;
		ans += backtrack(pos + 1); 
	}
	color[u] = 0;
	return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	long long ans = 1;
	up(i,1,n){
		if (!visited[i]){
			vertices.clear();
			dfs(i, 0);
			ans *= backtrack(0);
		}
	}
	cout << ans;
}