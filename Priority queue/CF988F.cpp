/*input
9 1 11
1 6
1 39
0 78
9 8
5 23
4 45
4 78
4 40
4 7
0 38
5 9
0 13
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2005;
vector< vector<pr> > G;
int d[N];
int end_point, n, m;
pr query[4005];
int numQuery = 0;
int shortestPath(int end_point){
	for(int i=1;i<=end_point;++i) d[i] = INT_MAX;
	d[0] = 0;
	priority_queue< pr, vector< pr >, greater < pr > > pq;
	pq.push({0, 0});
	while (pq.size()){
		int u = pq.top().second, val = pq.top().first;	pq.pop();
		// cout << u << ' ' << d[u] << '\n';
		if (d[u] != val) continue;
		if (u == end_point) return d[u];
		for (auto node : G[u]){
			int v = node.first, c = node.second;
			if (d[v] > d[u] + c){
				d[v] = d[u] + c;
				pq.push({d[v], v});
			}
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> end_point >> n >> m;
	G.assign(end_point+1, vector<pr>());
	query[numQuery++] = {0, INT_MIN};
	query[numQuery++] = {end_point, INT_MIN};
	for(int i=1;i<=n;++i){
		int l,r; cin >> l >> r;
		query[numQuery++] = {l, r};
	}
	for(int i=1;i<=m;++i){
		int x,p; cin >> x >> p;
		query[numQuery++] = {x, -1 * p};
	}
	sort(query, query + numQuery);
	// for(int i=0;i<numQuery;++i) cout << query[i].first << ' ' << query[i].second << '\n';
	// for the start point
	for (int i=1;i<numQuery;++i){
		if (query[i].second > 0) break;
		G[0].push_back({query[i].first, 0LL});
	}
	// having a umbrella
	for(int i=1;i<numQuery;++i){
		int u = query[i].first;
		if (query[i].second == INT_MIN) continue;
		if (query[i].second < 0) {
			for (int j=u+1;j<= end_point;++j){
				G[u].push_back({j, (j - u) * query[i].second * -1});
			}
		}
	}
	// after the rain
	for (int i=1;i<numQuery;++i){
		int u = query[i].second;
		if (query[i].second > 0){
			for(int j=i+1;j<numQuery;++j){
				if (query[j].second > 0) break;
				G[u].push_back({query[j].first, 0});
			}
		}
	}
	// for (auto v : G[0]) cout << v.first << ' ' << v.second << '\n';
	cout << shortestPath(end_point) << '\n';
}