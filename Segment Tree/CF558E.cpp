/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int C = 26;
char s[N];
int n,q;
int seg[4*N][C], lazy[4*N][C];
void lazyUpd(int u,int l,int r,int c){
	if (lazy[u][c] != -1){
		seg[u][c] = lazy[u][c] * (r-l+1);
		if (l != r){
			lazy[u*2][c] = lazy[u*2+1][c] = lazy[u][c];
		}
		lazy[u][c] = -1;
	}
}
void build(int u,int l,int r){
	if (l == r){
		seg[u][s[l] - 'a'] = 1;
	}
	else {
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		for(int i=0;i<C;++i)
			seg[u][i] = seg[u*2][i] + seg[u*2+1][i];
	}
}
void upd(int u,int l,int r,int segL,int segR, int val, int c){
	lazyUpd(u,l,r,c);
	if (l > r || l > segR || r < segL || segL > segR) return;
	if (segL <= l && r <= segR){
		seg[u][c] = val * (r - l + 1);
		if (l != r){
			lazy[u*2][c] = lazy[u*2+1][c] = val;
		}
	}
	else {
		upd(u*2,l,mid,segL,segR,val,c);
		upd(u*2+1,mid+1,r,segL,segR, val, c);
		seg[u][c] = seg[u*2][c] + seg[u*2+1][c];
	}
}
int get(int u,int l,int r,int segL,int segR,int c){
	lazyUpd(u,l,r,c);
	if (l > r || l > segR || r < segL) return 0;
	if (segL <= l && r <=  segR){
		return seg[u][c];
	}
	return get(u*2,l,mid,segL,segR,c) + get(u*2+1,mid+1,r,segL,segR,c);
}
int countingSort[C];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;++i) cin >> s[i];
	memset(lazy, -1, sizeof(lazy));
	build(1,1,n);
	while (q--){
		int segL,segR,up; cin >> segL >> segR >> up;
		for(int i=0;i<C;++i) countingSort[i] = get(1,1,n,segL,segR,i);
		for(int i=0;i<C;++i) upd(1,1,n,segL,segR,0,i);
		int l = segL;
		if (up){
			for(int i=0;i<C;++i){
				upd(1,1,n,l,l+countingSort[i]-1,1,i);
				l += countingSort[i];
			}
		}
		else {
			for(int i=C-1;i>=0;--i){
				upd(1,1,n,l,l+countingSort[i]-1,1,i);
				l += countingSort[i];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<C;++j) {
			if (get(1,1,n,i,i,j)) {
				char c = j + 'a';
				cout << c;
				break;
			}
		}
	}
}