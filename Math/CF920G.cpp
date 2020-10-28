/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1e6 + 5;
int t,x,p,k;
#define ll long long
int get(int n, int p){ // count the number of integer x that GCD(x, p) == 1 from 1...n
	vector<int> prime;
	for(int i=2;i*i <= p;++i){
		if (p % i == 0){
			prime.push_back(i);
			while (p % i == 0) p/=i;
		}
	}
	if (p > 1) prime.push_back(p);
	int sz = prime.size();
	int ans = 0;
	for(int mask=1;mask < (1 << sz);++mask){
		int cur = 1;
		for(int i=0;i<sz;++i) {
			if (bits(mask, i)) {
				cur *= prime[i];
			}
		}
		if (__builtin_popcount(mask) & 1) ans += n/cur;
		else ans -= n/cur;
	}
	return n - ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> x >> p >> k;
		int ans = 0;
		int l = x, r = 1e8;
		while (l <= r){
			if (get(mid,p) - get(x,p) >= k){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
}