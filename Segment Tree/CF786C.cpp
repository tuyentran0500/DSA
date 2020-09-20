/*input

*/
// https://codeforces.com/contest/786/problem/C
// PIT  
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int seg[55*N], L[55*N], R[55*N];
int root[N];
int cnt_id = 0;
int a[N], n;
int nxt[N], cur[N];
int build(int u,int l,int r){
	if (l == r){
		return u;
	}
	L[u] = build(++cnt_id,l,mid);
	R[u] = build(++cnt_id,mid+1,r);
	seg[u] = seg[L[u]] + seg[R[u]];
	return u; 
}
int upd(int u,int l,int r,int pos,int val){
	int id = ++cnt_id;
	if (l == r){
		seg[id] = seg[u] + val;
		return id;
	}
	if (l > r || l > pos || r < pos) return id;
	if (pos <= mid) L[id] = upd(L[u],l,mid,pos,val);
	else L[id] = L[u];
	if (pos > mid) R[id] = upd(R[u],mid+1,r,pos,val);
	else R[id] = R[u];
	seg[id] = seg[L[id]] + seg[R[id]];
	return id;
}
int find(int u,int k){
	int l = 1, r = n+1;
	while (l != r){
		if (seg[L[u]] <= k){
			k -= seg[L[u]];
			l = mid + 1;
			u = R[u];
		}
		else {
			r = mid;
			u = L[u];
		}
	}
	return l;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		cur[i] = n+1;
	}
	for(int i=n;i>=1;--i){
		nxt[i] = cur[a[i]];
		cur[a[i]] = i;
	}
	root[n+1] = build(1,1,n+1);
	for(int i=n;i>=1;--i){
		if (nxt[i] != n+1) {
			root[i] = upd(root[i+1],1,n+1,nxt[i],-1);
			root[i] = upd(root[i],1,n+1,i,1);
		} 
		else root[i] = upd(root[i+1],1,n+1,i,1);
	}
	for(int k=1;k<=n;++k){
		int ans = 0;
		for(int i=1;i<=n;++i){
			i = find(root[i],k) - 1;
			ans++;
		}
		cout << ans << '\n';
	}
}