/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
int a[N];
map<int,int> cnt;
int res[N];
int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	// y
	for(int i=1;i<=n;++i){
		res[i] = (i - 1 - cnt[a[i]-1] - cnt[a[i]] - cnt[a[i]+1]);
		cnt[a[i]]++;
	}
	cnt.clear();
	// -x
	for(int i=n;i>=1;--i){
		res[i] -= (n - i - cnt[a[i]-1] - cnt[a[i]] - cnt[a[i]+1]);
		cnt[a[i]]++;
	}
	// long double 12-byte
	long double ans = 0;
	up(i,1,n) ans += 1LL * res[i] * a[i];
	cout << fixed << setprecision(0) << ans;
}