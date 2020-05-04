/*input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 30005;
int seg[4*N], a[N];
int n,q;
#define mid ((l+r)/2)
void upd(int u,int l,int r,int pos){
	if (l > r || l > pos || r < pos) return;
	if (l == r) seg[u] = 1;
	else {
		upd(u*2,l,mid, pos);
		upd(u*2+1,mid+1,r,pos);
		seg[u]++;
	}
}
int get(int u,int l,int r,int L,int R){
	if (l > r || l > R || r < L) return 0;
	if (L <= l && r <= R) return seg[u];
	return  get(u*2,l,mid,L,R) + get(u*2+1,mid+1,r,L,R);
}
struct query{
	int l,r;
	int v, t;
	query() {}
	query(int T,int L,int R,int V) {
		l = L;
		r = R;
		v = V;
		t = T;
	}
};
bool operator<(query a,query b){
	return  (a.v == b.v ? a.t < b.t : a.v < b.v);
}
vector <query> v;
int ans[200005];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> a[i];
		v.push_back(query(0,i,i,a[i]));
	}
	cin >> q;
	up(i,1,q){
		int l,r,k; cin >> l >> r >> k;
		v.push_back(query(i,l,r,k));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(auto u : v){
		// cout << u.v << ' ' << u.l << ' ' << u.r << '\n';
		if (!u.t) upd(1,1,n,u.l);
		else {
			// cout << u.l << ' ' << u.r << '\n';
			ans[u.t] = get(1,1,n,u.l,u.r);
		}
	}
	up(i,1,q) cout << ans[i] << '\n';
}