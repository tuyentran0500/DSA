/*input

*/
// https://www.codechef.com/COOK106A/problems/XORCMPNT
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int logA = 30;
int a[N], n, m;
int t;
int basis[N], sz;
void init(){
	up(i,0,logA-1) basis[i] = 0; sz = 0;
}
void insertVector(int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		} 
		mask ^= basis[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		init();
		for (int i=1;i<=m;++i) {
			cin >> a[i];
			insertVector(a[i]);
		}
		int ans = 1;
		for (int i=1;i<=n-sz;++i) ans *= 2;
		cout << ans << '\n';
	}
}