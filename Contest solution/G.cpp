/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
#define int long long
using namespace std;
const int N = 100005;
ll dp[N], sumDp[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[1] = 1; sumDp[1] = 1;
	for(int i=2;i<=100000;++i){
		dp[i] = sumDp[(int)sqrt(i)];
		sumDp[i] = sumDp[i-1] + dp[i];
	}	
	int t; cin >> t;
	while (t--){
		ll x; cin >> x;
		ll x2 = sqrt(x);
		ll x4 = sqrt(x2);
		ll ans = 0;
		for(int i=1;i<=x4;++i) ans += (x2 - i*i + 1) * dp[i];
		cout << ans << '\n';
	}
}