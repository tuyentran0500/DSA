/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 100005;
const ll INF = 1e15;
const int mod = 1e9 + 2105;
#define int ll
int n,m,s,t;
vector<ll> ds, dt;
vector<pr> Gs[N], Gt[N];
int oks[N], okt[N], ok[N];
int minD = INF;
vector<ll> shortestPath(int s,int t, vector<pr> G[N]){
	vector<ll> d(n+1, INF);
	d[s] = 0;
	ok[s] = 1;
	priority_queue< pr, vector<pr>, greater<pr> > pq;
	pq.push({0, s});
	while (pq.size()){
		int u = pq.top().second, val = pq.top().first;
		pq.pop();
		if (val != d[u]) continue;
		for (auto node : G[u]){
			int v = node.first, c = node.second;
			if (d[v] == d[u] + c) ok[v] = (ok[v] + ok[u]) % mod;
			if (d[v] > d[u] + c){
				d[v] = d[u] + c;
				ok[v] = ok[u];
				pq.push({d[v], v});
			}
		}
	}
	minD = d[t];
	return d;	
}
struct query {
	int u,v,c;
	query(){u = v = c = 0;}
	query(int _u,int _v,int _c){u = _u; v = _v; c = _c;}
};
query edge[N];
void init(){
	ds = shortestPath(s, t, Gs);
	up(i,1,n) oks[i] = ok[i];
	memset(ok, 0, sizeof(ok));
	dt = shortestPath(t, s, Gt);
	up(i,1,n) okt[i] = ok[i];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	ds.assign(n+1, INF);
	dt.assign(n+1, INF);
	up(i,1,m){
		int u,v,c; cin >> u >> v >> c;
		Gs[u].push_back({v, c});
		Gt[v].push_back({u, c});
		edge[i] = query(u, v, c);
	}
	init();
	// up(i,1,n) cout << oks[i] << ' '; cout << '\n';
	up(i,1,m){
		int u = edge[i].u, v = edge[i].v, c = edge[i].c;
		if (ds[u] + dt[v] + c == minD && oks[u] * okt[v] % mod == oks[t]){
			cout << "YES\n";
			continue;
		} 
		ll paid = INF;
		if (ds[u] + dt[v] < minD) paid = min(paid, c - (minD - 1 - ds[u] - dt[v]));
		if (paid >= c) cout << "NO\n";
		else cout << "CAN " << paid << '\n';
	}
}