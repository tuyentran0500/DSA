/*input
6 2
1 3 2
4 6 3
1
3 4
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 50005;
#define MID ((L+R)/2)
const int INF = 1e9;
int seg[4*N], lazy[4*N];
int n,m,q;
void lazy_upd(int u,int l,int r){
	seg[u] += lazy[u];
	if (l != r) {
		lazy[u*2] += lazy[u];
		lazy[u*2+1] += lazy[u];
	}
	lazy[u] = 0;
}
void upd(int u,int L,int R,int l,int r,int d){
	lazy_upd(u,L,R);
	if (L > R || L > r || R < l) return; 
	if (l <= L && R <= r) {
		lazy[u] = d;
		lazy_upd(u,L,R);
	}
	else {
		upd(u*2,L,MID,l,r,d);
		upd(u*2+1,MID+1,R,l,r,d);
		seg[u] = max(seg[u*2], seg[u*2 + 1]);
	}
}
int get(int u,int L,int R, int l, int r){
	lazy_upd(u,L,R);
	if (L > R || L > r || R < l) return -INF;
	if (l <= L && R <= r) return seg[u];
	return max(get(u*2,L,MID,l,r), get(u*2+1,MID + 1, R,l,r));
} 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int l,r,d; cin >> l >> r >> d;
		upd(1,1,n,l,r,d);
	}
	cin >> q;
	up(i,1,q){
		int l,r; cin >> l >> r;
		cout << get(1,1,n,l,r) << '\n';
	}
}