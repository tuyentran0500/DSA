/*input

*/
// https://codeforces.com/contest/1101/problem/G
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int logA = 30;
int n,a[N];
int basis[N], sz = 0;
void insertVector(int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
		}
		mask^=basis[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int curXor = 0;
	for(int i=n;i>=1;--i){
		curXor ^= a[i];
		insertVector(curXor);
	}
	if (curXor == 0) cout << -1;
	else {
		cout << sz << '\n';
	}
}