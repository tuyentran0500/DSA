/*input
10
-100 -92 -72 -49 -46 -15 -1 51 79 86
-1 -8 8 -1 7 -2 -7 2 3
5
s 4 7
s 5 8
s 9 10
+ 3 62
s 3 5
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long 
const long long INF = -1e18;
using namespace std;
const int N = 100005;
int seg[4*N], lazy[4*N];
int a[N], k[N], sum[N], n;
void build(int u,int l,int r){
	if (l == r){
		seg[u] = a[l];
	}
	else {
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		seg[u] = seg[u*2] + seg[u*2+1];
	}
	lazy[u] = INF;
}
void lazy_upd(int u,int l,int r){
	if (lazy[u] == INF) return; 
	seg[u] = lazy[u] * (r - l + 1);
	if (l != r){
		lazy[u*2] = lazy[u];
		lazy[u*2+1] = lazy[u];
	}
	lazy[u] = INF;
}
int get(int u, int l,int r,int L,int R){
	lazy_upd(u,l,r);
	if (l > R || r < L) return 0;
	if (L <= l && r <= R) return seg[u];
	return get(u*2,l,mid,L,R) + get(u*2+1,mid+1,r,L,R);
}
void upd(int u,int l,int r,int L, int R,int val){
	lazy_upd(u,l,r);
	if (l > R || r < L) return;
	if (L <= l && r <= R) {
		lazy[u] = val;
		lazy_upd(u,l,r);
	}
	else {
		upd(u*2,l,mid,L,R,val);
		upd(u*2+1,mid+1,r,L,R,val);
		seg[u] = seg[u*2] + seg[u*2+1];
	}
}
void update(int pos,int add){
	int l = pos, r = n, ans = pos;
	int val = get(1,1,n,pos,pos);
	while (l <= r){
		if (val + add > get(1,1,n,mid,mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	upd(1,1,n,pos,ans,val + add);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	for(int i=1;i<n;++i) cin >> k[i], k[i] += k[i-1];
	for(int i=1;i<=n;++i) sum[i] = sum[i-1] + k[i-1];
	up(i,1,n) a[i] -= k[i-1];
	// up(i,1,n) cout << a[i] << ' ';
	build(1,1,n);
	int t; cin >> t;
	while (t--){
		char c; cin >> c;
		if (c == '+'){
			int pos,val; cin >> pos >> val;
			update(pos, val);
		}
		else {
			int l,r; cin >> l >> r;
			cout << get(1,1,n,l,r) + sum[r] - sum[l-1] << '\n';
		}
	}
}