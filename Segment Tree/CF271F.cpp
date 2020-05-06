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
const int N = 100005;
int seg[4*N], a[N];
pr mn[4*N];
int n,t;
int GCD(int a,int b){
	if (a == INT_MIN) return b;
	if (b == INT_MIN) return a;
	return __gcd(a,b);
}
pr operator+(pr a,pr b){
	if (a.first == b.first) return pr(a.first, a.second + b.second);
	return (a < b ? a : b);
}
void build(int u,int l,int r){
	if (l == r){
		seg[u] = a[l];
		mn[u] = pr(a[l],1);
	}
	else {
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		seg[u] = __gcd(seg[u*2], seg[u*2+1]);
		mn[u] = mn[u*2] + mn[u*2+1];
	}
}
int getGCD(int u,int l,int r,int L,int R){
	if (l > r || l > R || r < L) return INT_MIN;
	if (L <= l && r <= R) return seg[u];
	return GCD(getGCD(u*2,l,mid,L,R), getGCD(u*2+1,mid+1,r,L,R));
}
pr getMin(int u,int l,int r,int L,int R){
	if (l > r || l > R || r < L) return pr(INT_MAX,0);
	if (L <= l && r <= R) return mn[u];
	return getMin(u*2,l,mid,L,R) + getMin(u*2+1,mid+1,r,L,R);
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	build(1,1,n);
	cin >> t;
	while(t--){
		int l,r; cin >> l >> r;
		int gGCD = getGCD(1,1,n,l,r);
		pr gMin = getMin(1,1,n,l,r);
		// cout << gGCD << ' ' << gMin.first << '\n';
		cout << (gMin.first == gGCD ? r-l + 1 - gMin.second : r-l+1) << '\n';
	}
}