/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define int long long
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 300005;
map<long long,long long> cnt;
int a[N], n, mod, k;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> mod >> k;
	long long ans = 0;
	up(i,1,n) {
		cin >> a[i];
		long long res = (a[i] * a[i]) % mod;
		res *= res; res %= mod;
		res -= 1LL * k * a[i]; res += 1LL * mod * mod; res %= mod;
		ans += cnt[res]++;
	}
	cout << ans;
}