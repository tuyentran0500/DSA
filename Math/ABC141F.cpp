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
const int LOG_N = 60;
const int N = 100005;
long long n, a[N], xorSum = 0;
long long basic[LOG_N];
void insertVector(long long mask){
	for (int i=LOG_N-1;i>=0;--i){
		if (bits(mask, i) == 0) continue;
		if (!basic[i]) {
			basic[i] = mask;
			return;
		}
		else mask ^= basic[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		xorSum ^= a[i];
	}
	for(int i=0;i<LOG_N;++i) {
		if (bits(xorSum, i)){
			for(int j=1;j<=n;++j) if (bits(a[j], i)) a[j] -= (1LL << i);
		}
	}
	for(int i=1;i<=n;++i) insertVector(a[i]);
	long long maxXor = 0;
	for(int i=LOG_N-1;i>=0;--i){
		if (!basic[i]) continue;
		if (bits(maxXor, i)) continue;
		maxXor ^= basic[i];
	}
	// cout << maxXor << '\n';
	cout << (maxXor * 2 + xorSum);
}