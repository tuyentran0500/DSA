/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int M = 1 << 5;
int mx[M][4*N]; // really ????
int a[N][5];
int n,q,k;
int sum(int mask,int id){
	int ans = 0;
	for(int i=0;i<k;++i) ans += (bits(mask, i) ? 1 : -1) * a[id][i]; 
	return ans;
}
void build(int mask,int u,int l,int r){
	if (l == r){
		mx[mask][u] = sum(mask, l);
	}
	else {
		build(mask, u*2, l, mid);
		build(mask, u*2+1,mid+1,r);
		mx[mask][u] = max(mx[mask][u*2], mx[mask][u*2+1]);
	}
}
void upd(int mask,int u,int l,int r,int pos){
	if (l > pos || r < pos) return;
	if (l == r){
		mx[mask][u] = sum(mask, pos);
	}
	else {
		upd(mask, u*2, l, mid, pos);
		upd(mask, u*2 + 1, mid+1, r, pos);
		mx[mask][u] = max(mx[mask][u*2], mx[mask][u*2+1]);
	}
}
void update(int pos){
	for(int mask = 0; mask < (1 << k); ++mask){
		upd(mask, 1,1,n, pos);
	}
}
int getMX(int mask,int u,int l,int r,int L,int R){
	if (l > R || r < L) return INT_MIN;
	if (L <= l && r <= R) return mx[mask][u];
	return max(getMX(mask, u*2,l,mid, L, R), getMX(mask, u*2+1,mid+1,r,L,R));	
}
int get(int L,int R){
	int ans = 0;
	int FULL = (1 << k) - 1;
	for(int mask = 0; mask < (1 << k); ++mask){
		ans = max(ans, getMX(mask,1,1,n,L,R) + getMX(FULL ^ mask,1,1,n,L,R));
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) up(j,0,k-1) cin >> a[i][j];
	// cout << sum(1, 1) << '\n';
	cin >> q;
	for(int mask=0;mask<(1 << k);++mask) build(mask,1,1,n);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int id; cin >> id;
			for(int i=0;i<k;++i) cin >> a[id][i];
			update(id);
		}
		else {
			int l,r; cin >> l >> r;
			cout << get(l, r) << '\n';
		}
	}
}