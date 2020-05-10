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
const int N = 10005;
int n,m;
vector<int> G[N];
vector<int> topo;
int d[N];
void solve(){
	priority_queue< pr, vector<pr>, greater<pr> > pq;
	for(int i=1;i<=n;++i) pq.push(pr(d[i],i));
	while (pq.size()){
		pr u = pq.top(); pq.pop();
		if (d[u.second] != u.first) continue;
		if (!u.first) {
			topo.push_back(u.second);
			for(auto v : G[u.second]){
				d[v]--;
				pq.push(pr(d[v],v));
			}
		}
	}
	if (topo.size() != n) cout << "Sandro fails.";
	else {
		for(auto v: topo) cout << v << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int x,y; cin >> x >> y;
		G[x].push_back(y);
		d[y]++;
	}
	solve();
}