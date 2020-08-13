/*input

*/
// https://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/S
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1e5 + 5;
const int logA = 30;
int t;
int basis[logA], sz = 0;
void insertVector(int mask){
	for(int i=logA-1;i>=0;--i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			// cout << i << ' ' << basis[i] << '\n';
			return;
		}
		mask^=basis[i];
	}
}
int trace(int k){
	int ans = 0;
	int curSZ = sz;
	// cout << sz << '\n';
	for(int i=logA-1;i>=0;--i){
		if (!basis[i]) continue;
		int cur =  (1 << (--curSZ));
		if (k >= cur) {
			k-= cur;
			if (!bits(ans,i)) ans ^= basis[i];
		}
		else {
			if (bits(ans,i)) ans ^= basis[i];
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		int tp, k; cin >> tp >> k;
		if (tp == 1) insertVector(k);
		else cout << trace(--k) << '\n';
	}	
}