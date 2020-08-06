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
const int N = 105;
pr p[N];
int n;
bool angle(pr a, pr b){
	return atan2(a.first, a.second) < atan2(b.first, b.second);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i) cin >> p[i].first >> p[i].second;
	sort(p, p+n, angle);
	long long ans = 0;
	for(int i=0;i<n;++i){
		long long curX = 0, curY = 0;
		for(int j=0;j<n;++j){
			int pi = (i + j) % n;
			curX += p[pi].first;
			curY += p[pi].second;
			ans = max(ans, curX * curX + curY * curY);
		}
	}
	// cout << ans << '\n';
	cout << setprecision(15) << sqrt(ans);
}
