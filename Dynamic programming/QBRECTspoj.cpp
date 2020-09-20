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
const int N = 1005;
bool a[N][N];
int h[N][N], r[N][N], l[N][N];
int n,m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) up(j,1,m) cin >> a[i][j];
	int res = 0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (!a[i][j]) {
				l[i][j] = r[i][j] = j;
				continue;
			}
			h[i][j] = 1 + h[i-1][j];
			int curPos = j-1;
			while (curPos && h[i][curPos] >= h[i][j]) curPos = l[i][curPos];
			l[i][j] = curPos;
		}
		for(int j=m;j>=1;--j){
			if (!a[i][j]) continue;
			int curPos = j+1;
			while (curPos <= m && h[i][curPos] >= h[i][j]) curPos = r[i][curPos];
			r[i][j] = curPos;
		}
		for(int j=1;j<=m;++j) res = max(res, (r[i][j] - l[i][j] - 1) * h[i][j]);
	}
	// up(i,1,n){
	// 	up(j,1,m) {
	// 		cout << l[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	cout << res;
}