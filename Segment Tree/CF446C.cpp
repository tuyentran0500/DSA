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
const int N = 300005;
const int mod = 1000000009;
const int C = 276601605, A = 691504013, B = 308495997;
int seg[4*N], a[N]; 
long long pa[N],fa[N], pb[N], fb[N];
long long la[4*N], lb[4*N];
int n,m;
int f[N];
void precal(){
	pa[0] = pb[0] = fa[0] = fb[0] = 1;
	for(int i=1;i<=n;++i){
		pa[i] = (pa[i-1] * A) % mod;
		pb[i] = (pb[i-1] * B) % mod;
		fa[i] = (fa[i-1] + pa[i]) % mod;
		fb[i] = (fb[i-1] + pb[i]) % mod;
	}
}
void build(int u,int l,int r){
	if (l == r){
		seg[u] = a[l];
	}
	else {
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		seg[u] = (seg[u*2] + seg[u*2+1]) % mod;
	}
}
void lazyUpd(int u,int l,int r){
	if (!la[u]) return;
	if (l != r){
		la[u*2] = (la[u*2] + la[u]) % mod; 
		lb[u*2] = (lb[u*2] + lb[u]) % mod;
		la[u*2+1] = (la[u*2+1] + la[u] * pa[mid + 1 - l]) % mod;
		lb[u*2+1] = (lb[u*2+1] + lb[u] * pb[mid + 1 - l]) % mod;
	}
	long long res = (la[u] * fa[r-l]) % mod;
	res = (res - lb[u] * fb[r-l] + 1LL * mod * mod) % mod;
	seg[u] = (seg[u] + 1LL * C * res) % mod;
	la[u] = lb[u] = 0;
}
void upd(int u,int l,int r,int L,int R){
	lazyUpd(u,l,r);
	if (l > r || l > R || r < L) return;
	if (L <= l && r <= R) {
		la[u] = pa[l - L + 1];
		lb[u] = pb[l - L + 1];
		lazyUpd(u,l,r);
	}
	else {
		upd(u*2,l,mid,L,R);
		upd(u*2+1,mid+1,r,L,R);
		seg[u] = (seg[u*2] + seg[u*2+1]) % mod;
	}
}
int getSum(int u,int l,int r,int L,int R){
	lazyUpd(u,l,r);
	if (l > r || l > R || r < L) return 0;
	if (L <= l && r <= R) return seg[u];
	return (getSum(u*2,l,mid,L,R) + getSum(u*2+1,mid+1,r,L,R)) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) cin >> a[i];
	precal();
	build(1,1,n);
	up(i,1,n) f[i] = (f[i-1] + f[i]) % mod;
	for(int i=1;i<=m;++i){
		int t,l,r; cin >> t >> l >> r;
		// up(j,1,n) cout << getSum(1,1,n,j,j) << ' '; cout << '\n';
		if (t == 1) upd(1,1,n,l,r);
		else cout << getSum(1,1,n,l,r) << '\n';
	}
}