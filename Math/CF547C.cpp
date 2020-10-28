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
const int maxVal = 500005;
int cnt[maxVal], a[N];
vector<int> prime[N];
int ok[N];
int n,q;
// use the same approach with: https://codeforces.com/contest/920/problem/G  
void init(){
	up(i,1,n) {
		int cur = a[i];
		for(int j=2;j*j<=cur;++j){
			if (cur % j == 0){
				prime[i].push_back(j);
				while (cur % j == 0) cur/=j;
			}
		}
		if (cur > 1) prime[i].push_back(cur);
	}
}
int curSZ = 0;
// get the number of number x, that GCD(x, a[pos]) = 1.
int get(int pos){
	int sz = prime[pos].size();
	int res = 0;
	for(int mask=1;mask < (1 << sz);++mask){
		int cur = 1;
		for(int j=0;j<sz;++j){
			if (bits(mask, j)) cur *= prime[pos][j];
		}
		if (__builtin_popcount(mask) & 1) res += cnt[cur];
		else res -= cnt[cur]; 
	}
	return curSZ - res;
}
void upd(int p,int val){
	curSZ+=val;
	for(int i=1;i * i <= p; ++i){
		if (p == i * i){
			cnt[i]+=val;
			break;
		}
		if (p % i == 0){
			cnt[i]+=val;
			cnt[p/i]+=val;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	up(i,1,n) {
		cin >> a[i];
	}
	init();
	long long ans = 0;
	up(i,1,n) ok[i] = -1;
	while (q--){
		int pos; cin >> pos;
		ok[pos] *= -1;
		if (a[pos] == 1){
			if (ok[pos] == 1) ans += curSZ;
			else ans -= (curSZ-1);
		}	
		else ans += 1LL * ok[pos] * get(pos);
		upd(a[pos], ok[pos]);
		cout << ans << '\n';
	}
}