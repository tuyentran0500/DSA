/*input
5
1 2
1 3
3 4
3 5
9
1 1 5
1 3 3
2 1 3
1 1 100000
1 2 100000
2 2 3
2 1 3
1 5 2
2 4 5
*/
// https://codeforces.com/gym/102694/problem/E
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define mid ((l+r)/2)
using namespace std;
const int N = 300005;
const double INF = log(1e9);
int L[N], R[N];
double seg[4*N];
vector<int> G[N];
int counter = 0;
int n,q;
void dfs(int u,int par){
	L[u] = ++counter;
	for(auto v : G[u]){
		if (v == par) continue;
		dfs(v, u);
	}
	R[u] = counter;
}
void upd(int u,int l,int r,int pos,double val){
	if (l > r || r < pos || l > pos) return;
	if (l == r){
		seg[u] = log(val);
	}
	else {
		upd(u*2,l,mid,pos,val);
		upd(u*2+1,mid+1,r,pos,val);
		seg[u] = seg[u*2] + seg[u*2+1];
	}
}
double getSubtree(int u,int l,int r,int pos){
	#define segL L[pos]
	#define segR R[pos]
	if (l > segR || r < segL || l > r) return 0;
	if (segL <= l && r <= segR) return seg[u];
	return getSubtree(u*2,l,mid,pos) + getSubtree(u*2+1,mid+1,r,pos);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<n;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> q;
	dfs(1, 0);
	// up(i,1,n) cout << L[i] << ' ' << R[i] << '\n';
	for(int i=1;i<=q;++i){
		int t,x,y; cin >> t >> x >> y;
		if (t == 1) upd(1,1,n,L[x], 1.0 * y);
		else {
			double ans = getSubtree(1,1,n,x) - getSubtree(1,1,n, y);
			if (ans >= INF) cout << 1000000000 << '\n';
			else cout << fixed << setprecision(12) << 1.0 * exp(ans) << '\n';
		}
	}
}