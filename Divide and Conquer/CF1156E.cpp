/*input
15
4 8 11 2 5 13 6 9 12 7 3 10 14 15 1 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int logN = 18;
int a[N], pos[N];
int mx[N][logN];
int n;
int get(int l,int r){
	int k = log2(r - l + 1);
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}	
void init(){
	for(int i=1;i<=n;++i) mx[i][0] = a[i];
	for(int j=1;j<logN;++j){
		for(int i=1;i + (1 << j) - 1 <= n; ++i){
			mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j-1))][j-1]);
		} 
	}
}
long long solve(int l,int r){
	if (l > r) return 0;
	int mxVal = get(l,r), mid = pos[mxVal];
	long long ans = 0;
	if (mid < (l+r)/2){
		for(int i=l;i<mid;++i) {
			int p = pos[mxVal - a[i]];
			if (p < l || p > r) continue;
			ans += (p > mid);
		}
	}
	else {
		for(int i=mid+1;i<=r;++i) {
			int p = pos[mxVal - a[i]];
			if (p < l || p > r) continue;
			ans += (p < mid);
		}
	}
	return ans + solve(l,mid-1) + solve(mid+1,r);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	init();
	// cout << get(4, 12) << '\n';
	cout << solve(1,n);
}