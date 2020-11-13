/*input
5
1000
12345
210500
210500210500
1234567891234
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
ll n;
int t;
ll dir[] = {0, 2, 3, 1};
ll solve(ll n){
	if (n <= 3) return n;
	int maxBIT = 0;
	while (1LL << (2*maxBIT + 2) <= n) maxBIT++;
	n -= ((1LL << (2*maxBIT)) - 1);
	// cerr << maxBIT << ' ' << (4LL << (maxBIT)) << '\n';
	ll a = (n/3) + (n % 3 != 0); a--;
	ll b = 0;
	for(int i=0;i<=maxBIT;++i){
		int cur = (bits(a, i*2+1) << 1) + bits(a, i*2);
		b += (dir[cur] << (2*i));
	}
	if (n % 3 == 0) return (3LL << (2*maxBIT)) + (a ^ b);
	if (n % 3 == 1) return (1LL << (2*maxBIT)) + a;
	return (2LL << (2*maxBIT)) + b;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		cout << solve(n) << '\n';
	}
}