/*input
5 8
2 1 4
3 1 4
4 1 5
5 2 3
4 5 2
4 5 4
1 4 4
3 4 2
1
2 2 1
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define sp pair<int,pr>
using namespace std;
const int N = 500005;
const int logN = 19;
pr edge[N];
int cEdge[N];
int n,m,q;
// disjoin-set
int pset[N], ver[N];
int finds(int u){
	return (pset[u] == u ? u : pset[u] = finds(pset[u]));
}
void joins(int u,int v){
	pset[finds(u)] = finds(v);
}

// rollback.
int pset2[N], cntVer;
int finds2(int u){
	if (ver[u] != cntVer) ver[u] = cntVer, pset2[u] = pset[u];
	return (pset2[u] == u ? u : pset2[u] = finds2(pset2[u]));
}
void joins2(int u,int v){
	pset2[finds2(u)] = finds2(v);
}

void init(){
	up(i,1,n) pset[i] = i; 
}
int ans[N];
vector< pr > query[N];
vector< pr > G[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int u,v,c; cin >> u >> v >> c;
		edge[i] = {u,v}; cEdge[i] = c;
		G[c].push_back({u,v});
	}	
	init();
	cin >> q;
	up(i,1,q){
		int k; cin >> k;
		while(k--) {
			int id; cin >> id;
			query[cEdge[id]].push_back({i, id}); // question_id, edge_id;
		}
	}
	up(w,1,500000){
		sort(query[w].begin(), query[w].end());
		for(auto it : query[w]) {
			int u = edge[it.second].first, v = edge[it.second].second; 
			finds(u); finds(v);
		}
		for(int i=0; i < query[w].size();){
			cntVer++;
			int question = query[w][i].first;
			while (i < query[w].size() && query[w][i].first == question){
				int id = query[w][i].second, u = edge[id].first, v = edge[id].second;
				if (finds2(u) != finds2(v)) {
 					joins2(u, v);
				}
				else {
					ans[question] = 1;
				}
				i++;
			}
		}
		cntVer++;
		for(auto it : G[w]){
			int u = it.first, v = it.second;
			if (finds(u) != finds(v)) {
				joins(u,v);
			}
		}
	}
	up(i,1,q) if (ans[i]) puts("NO"); else puts("YES");
}