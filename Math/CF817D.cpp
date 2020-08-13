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
const int N = 1000005;
int a[N], n;
int lmin[N], rmin[N], lmax[N], rmax[N];
void init(){
	lmin[1] = 1;
	for(int i=2;i<=n;++i){
		int j = i - 1;
		for(;j >= 1 && a[j] >= a[i]; j = lmin[j] - 1);
		lmin[i] = j + 1;
	}
	rmin[n] = n;
	for(int i=n-1;i>=1;--i){
		int j = i + 1;
		for (;j <= n && a[j] > a[i]; j = rmin[j] + 1);
		rmin[i] = j - 1;
	} 
	lmax[1] = 1;
	for(int i=2;i<=n;++i){
		int j;
		for(j = i-1; j >= 1 && a[j] <= a[i]; j = lmax[j] - 1);
		lmax[i] = j + 1;
	}
	rmax[n] = n;
	for(int i=n-1;i>=1;--i){
		int j;
		for (j=i+1; j <= n && a[j] < a[i]; j = rmax[j] + 1);
		rmax[i] = j - 1;
	} 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	init();
	long long ans = 0;
	// up(i,1,n) cout << lmin[i] << ' ' << rmin[i] << '\n';
	// up(i,1,n) cout << lmax[i] << ' ' << rmax[i] << '\n';

 	for(int i=1;i<=n;++i){
		ans += 1LL * (i - lmax[i] + 1) * (rmax[i] - i + 1) * a[i];
		ans -= 1LL * (i - lmin[i] + 1) * (rmin[i] - i + 1) * a[i];
	}
	cout << ans;
}