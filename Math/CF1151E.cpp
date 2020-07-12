/*input

*/
// https://codeforces.com/contest/1151/problem/E
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)	
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int a[N];
int n;
long long ans = 0;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n){
		if (a[i] >= a[i-1]) ans += 1LL * (a[i] - a[i-1]) * (n - a[i] + 1);
		else ans += 1LL * a[i] * (a[i-1] - a[i]);
	}
	cout << ans;
}