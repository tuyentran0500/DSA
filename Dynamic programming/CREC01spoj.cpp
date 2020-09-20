/*input

*/
// https://vn.spoj.com/problems/CREC01/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1005;
int h[N][N], l[N][N];
long long ans[N][N];
int n,m;
char a[N][N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) up(j,1,m) cin >> a[i][j];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (a[i][j] == '0') {
				l[i][j] = j; 
				continue;
			}
			h[i][j] = 1 + h[i-1][j];
			int curPos = j-1;
			while (curPos && h[i][curPos] >= h[i][j]) curPos = l[i][curPos];
			l[i][j] = curPos;
			ans[i][j] = ans[i][l[i][j]] + 1LL * h[i][j] * (j - l[i][j]); 
		}
	}
	long long res = 0;
	up(i,1,n) up(j,1,m) res += ans[i][j];
	cout << res;
}