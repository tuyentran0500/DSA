#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
const int N = 1e5 + 5;
int a[N], n;
int seg[4*N];
void upd(int u,int l,int r,int pos){
	if (l > pos || r < pos) return;
	if (l == r) seg[u]++;
	else {
		upd(u*2,l,mid,pos);
		upd(u*2+1,mid+1,r,pos);
		seg[u] = seg[u*2] + seg[u*2+1];
	}
}
int findMedian(int val){
	int u = 1, l = 0, r = N-1;
	while (l != r){
		if (seg[u*2] >= val){
			r = mid;
			u*=2;
		}
		else {
			val -= seg[u*2];
			l = mid + 1;
			u*=2; u++;
		}
	}
	return l;
}
int main(){
	// freopen("solve.inp","r", stdin);
	// freopen("solve.out","w", stdout);
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		upd(1,0,N-1,a[i]);
		int left = findMedian((i+1)/2), right = findMedian((i+2)/2);
		cout << (left + right)/2.0 << '\n';
	}
}