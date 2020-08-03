/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1005;
vector < vector<int> > G; // G[i] là tập cách đỉnh kề với i.  
int n,m;
int t; // số test.
int source;
int d[N]; // d[i] khoảng cách giữa đỉnh source và đỉnh i.  
void bfs(int source){
	memset(d, -1, sizeof(d));
	queue< int > q; // {d[u], u}
	d[source] = 0;	q.push(source);
	while (q.size()){
		int u = q.front();	q.pop();
		for (auto v : G[u]){
			if (d[v] != -1) continue;
			q.push(v);
			d[v] = d[u] + 1;
		} 
	}
	for(int i=1;i<=n;++i){
		if (i == source) continue;
		cout << (d[i] == -1 ? -1 : d[i] * 6) << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		G.assign(n+1, vector<int>());
		for(int i=1;i<=m;++i){
			int u, v; cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cin >> source;
		bfs(source);
	}
}