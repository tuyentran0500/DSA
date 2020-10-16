/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
long long s[N], a[N];
int n,k;
long long get(int l,int r){
	return s[r] - s[l-1];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	up(i,1,n) s[i] = s[i-1] + a[i];
	long long ans = 0, cur = 0;
	down(i,k,1) cur += a[i] * (k - 1 - (k - i) * 2);
	int l = 1;
	ans = cur;
	cout << cur << '\n';
	up(r,k+1,n){
		cur += (a[l] + a[r]) * (k-1) - 2 * get(l+1,r-1);
		l++;
		ans = min(ans, cur);
	}
	cout << ans;
}