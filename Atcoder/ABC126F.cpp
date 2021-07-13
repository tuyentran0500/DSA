#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 20;
int m, k;
int xorSum[4];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> k;
	if (!m){
		cout << (k == 0 ? "0 0" : "-1");
		return 0;
	}
	if (m == 1){
		for(int mask=0;mask<(1 << 4); ++mask){
			if (__builtin_popcount(mask) != 2) continue;
			up(i, 0, 3) xorSum[i+1] = xorSum[i] ^ bits(mask, i);
			bool flag = 1;
			up(i,0,3) up(j,i+1,3) 
				if (bits(mask, i) == bits(mask, j) && (xorSum[j+1] ^ xorSum[i]) != k) flag = 0;
			if (flag){
				up(i,0,3) cout << bits(mask, i) << ' ';
				return 0;
			}
		}
		cout << -1;
		return 0;
	}
	if (k >= (1 << m)) {
		cout << -1;
		return 0;
	}
	// Always remember xor sum 0....(2^n-1) = 0.
	for(int i=0;i<(1 << m); ++i) if (i != k) cout << i << ' ';
	cout << k << ' ';
	for(int i=(1 << m) - 1; i >= 0;--i) if (i != k) cout << i << ' ';
	cout << k << '\n';
}