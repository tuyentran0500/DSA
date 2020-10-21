/*input
3
1 1 3
3 2 5
3 1 7
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 300005;
int seg[4 * N], lazy[4 * N];
struct query {
	long long l,r,t;
	query(){l = r = t = 0;}
	query(int _t,int _l,int _r) {t = _t; l = _l; r= _r;}
};
query a[N]; 
int q, n;
vector<long long> b;
#define pos(x) (upper_bound(b.begin(), b.end(), x) - b.begin())
void querryType(int u,int l,int r){
	if (!lazy[u]) return;
	if (lazy[u] == 1) { // turn the whole segment into 1.
		seg[u] = (r - l + 1);
	}
	else if (lazy[u] == 2){ // turn the whole segment into 0.
		seg[u] = 0;
	}
	else seg[u] = (r - l + 1) - seg[u];
}
void lazyFunction(int &u, int v){
	if (v == 3) {
		u = 3 - u;
		return;
	}
	u = v;
}
void lazy_upd(int u,int l,int r){
	if (!lazy[u]) return;
	querryType(u,l,r);
	if (l != r) {
		lazyFunction(lazy[u*2],lazy[u]);
		lazyFunction(lazy[u*2+1],lazy[u]);
	}
	lazy[u] = 0;
}
void upd(int u,int l,int r,int L,int R, int t){
	lazy_upd(u,l,r);
	if (l > r || l > R || r < L) return;
	if (L <= l && r <= R){
		lazy[u] = t;
		lazy_upd(u,l,r);
	}
	else {
		upd(u*2,l,mid,L,R,t);
		upd(u*2+1,mid+1,r,L,R,t);
		seg[u] = seg[u*2] + seg[u*2+1];
	}
}
int get(int u,int l,int r,int L,int R){
	if (l > r || l > R || r < L) return 0;
	lazy_upd(u,l,r);
	if (L <= l && r <= R) return seg[u];
	return get(u*2,l,mid,L,R) + get(u*2+1, mid+1, r, L, R);
}
int bSearch(){
	int u = 1, l = 1, r = n;
	lazy_upd(u,l,r);
	while (l != r){
		lazy_upd(u*2,l,mid);
		lazy_upd(u*2+1,mid+1,r);
		if (seg[u*2] != mid - l + 1) {
			u*=2;
			r = mid;
		}
		else {
			u = u*2 + 1;
			l = mid + 1;
		}
	}
	return l;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> q;
	b.push_back(1);
	up(i,1,q){
		int t,l,r; cin >> t >> l >> r;
		a[i] = query(t, l, r);
		b.push_back(l);
		b.push_back(r);
		b.push_back(r + 1);
	}
	// data compression
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	// for(auto v : b) cout << v << ' '; cout << '\n';
	n = b.size();
	for(int i=1;i<=q;++i){
		int l = pos(a[i].l), r = pos(a[i].r), t = a[i].t;
		upd(1,1,n,l,r,t);
		// get(1,1,n,l,r);
		// for(int j=1;j<=n;++j) cout << get(1,1,n,j,j) << ' ';
		cout << b[bSearch() - 1] << '\n';
	}
}