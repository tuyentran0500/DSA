/*input
4
-1 -2 -3 -4
4
1 1 3
0 3 3 
1 2 4
1 3 4
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
using namespace std;
const int INF = 1e9;
const int N = 50005;
int n,m;
int a[N];
struct segment_tree{
	struct node{
		int lmax, rmax, sum, smax;
		node(){lmax = rmax = sum = smax = 0;}
		node(int v){
			lmax = rmax = sum = smax = v;
		}
		node(int l,int r,int s,int sm){
			lmax = l;
			rmax = r;
			sum = s;
			smax =sm;
		}
	};
	vector<node> st;
	segment_tree(){
		st.assign(4*n, node());
		build(1,1,n);
	};
	node merge(node l, node r){
		return node(max(l.lmax, l.sum + r.lmax),
					max(r.rmax, r.sum + l.rmax),
					l.sum + r.sum,
					max (max(l.smax, r.smax), r.lmax + l.rmax) 
			);
	}
	
	void build(int u,int l,int r){
		if (l == r){
			st[u] = node(a[l]);
		}
		else {
			build(u*2,l,mid);
			build(u*2+1,mid+1,r);
			st[u] = merge(st[u*2], st[u*2+1]);
		}
	}
	void upd(int u,int l,int r,int pos){
		if (l > r || l > pos || r < pos) return;
		if (l == r){
			st[u] = node(a[pos]);
		}
		else {
			upd(u*2,l,mid,pos);
			upd(u*2+1,mid+1,r,pos);
			st[u] = merge(st[u*2], st[u*2+1]);
		}
	}
	node get(int u,int l,int r,int L, int R){
		if (l > r || l > R || r < L) return node(INT_MIN);
		if (L <= l && r <= R) return st[u];
		node p1 = get(u*2,l,mid,L,R);
		node p2 = get(u*2+1,mid+1,r,L,R);
		if (p1.sum == INT_MIN) return p2;
		if (p2.sum == INT_MIN) return p1;
		return merge(p1,p2);
	}
	void updM(int pos){
		upd(1,1,n,pos);
	}
	int getM(int l,int r){
		return get(1,1,n,l,r).smax;
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n)	cin >> a[i];
	segment_tree st;
	cin >> m;
	up(i,1,m){
		int t,l,r;	cin >> t >> l >> r;
		if (!t) {
			a[l] = r;
			st.updM(l);
		}
		else {
			cout << st.getM(l,r) << '\n';
		}
	}
}