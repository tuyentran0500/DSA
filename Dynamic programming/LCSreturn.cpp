/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 5005;
const int ASCII = 200;
int p[N][N], s[N][N];
bool ok[N][ASCII];
string a,b;
int n,m;
int mxLCS, ans;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	n = a.size();   a = "#" + a; 
	m = b.size();	b = "#" + b;
	// up(i,1,m) {up(j,0,1) cout << nxt[i][j] << ' '; cout << '\n';}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (a[i] == b[j]) p[i][j] = p[i-1][j-1] + 1;
			else p[i][j] = max(p[i-1][j], p[i][j-1]);
		}
	}
	mxLCS = p[n][m];
	for(int i=n;i>=1;--i){
		for(int j=m;j>=1;--j) {
			if (a[i] == b[j]) s[i][j] = s[i+1][j+1] + 1;
			else s[i][j] = max(s[i+1][j], s[i][j+1]);
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=0;i<=n;++i){
			if (p[i][j-1] + s[i+1][j+1] == mxLCS) {
				ok[i][b[j]] = 1;
			}
		}
	}
	up(i,0,n) up(j,0,ASCII-1) ans += ok[i][j];
	cout << ans;
}