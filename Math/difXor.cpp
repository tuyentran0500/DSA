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
const int N = 100005;
const int logA = 20;
int a[N], n;
int basis[N], sz;
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
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> a[i];
		insertVector(a[i]);
	}
	cout << (1 << sz);
}