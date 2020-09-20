/*input
6 6 1
1 2 
1 5
2 3
2 4
5 6
4 1 1 2 2 3
1 2 3 4 5 6
*/
// https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree/problem
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int color[N], n, root, m;
int c[N];
int le[N], ri[N],cnt;
vector<int> G[N];
int ans[N], bit[N], prevPos[N];
struct query {
	int l,r,t;
	query(){l = r = t = 0;}
	query(int _l,int _r,int _t) {l = _l; r = _r; t = _t;}
};
bool operator<(query a, query b){
	if (a.r == b.r) return a.t < b.t;
	return a.r < b.r;
}
void upd(int u, int val){
	while (u < N){
		bit[u] += val;
		u += (u & -u);
	}
}
int get(int u){
	int ans = 0;
	while (u){
		ans += bit[u];
		u -= (u & -u);
	}
	return ans;
}

void zip(){
	vector<int> b;
	up(i,1,n) b.push_back(color[i]);
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for(int i=1;i<=n;++i){
		color[i] = lower_bound(b.begin(), b.end(), color[i]) - b.begin() + 1;
	}
}
void dfs(int u,int pre){
	le[u] = ++cnt;
	c[le[u]] = color[u];
	for (auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
	}
	ri[u] = cnt;
}
vector< query > qList;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> root;
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	up(i,1,n) cin >> color[i];
	zip();
	dfs(root, 0);
	up(i,1,n){
		qList.push_back(query(le[i], le[i], 0));
	}
	up(i,1,m){
		int u; cin >> u;
		qList.push_back(query(le[u],ri[u],i));
	}
	sort(qList.begin(), qList.end());
	for (auto cur : qList){
		if (cur.t){
			ans[cur.t] = get(cur.r) - get(cur.l - 1);
		}
		else {
			int pos = cur.l;
			if (prevPos[c[pos]]) upd(prevPos[c[pos]], -1);
			upd(pos, 1);
			prevPos[c[pos]] = pos;
		}
	}
	for(int i=1;i<=m;++i) cout << ans[i] << '\n';
}