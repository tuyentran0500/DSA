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
const int M = 2000005;
int a[N];
int cnt[M];
int n,k;
int get(int l,int r){
	return cnt[r] - cnt[l-1];
} 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	int mxVal = 0;
	int mnVal = INT_MAX;
	up(i,1,n) {
		cin >> a[i];
		cnt[a[i]]++;
		mxVal = max(a[i], mxVal);
		mnVal = min(a[i], mnVal);
	}
	up(i,1,mxVal+k) cnt[i] += cnt[i-1];
	int ans = min(k, mnVal);
	for(int i=k+1;i<=mxVal;++i){
		int res = 0;
		for(int j=1;j * i <= mxVal;++j){
			res += get(j*i, j*i+k);
		}
		// cout << i << ' ' << res << '\n';
		if (res == n) ans = i;
	}
	cout << ans;
}