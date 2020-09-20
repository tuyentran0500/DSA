/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int APHABET = 'z' - 'a';
int nxt[N][30], prv[N][30], p[N], s[N];
int ans[N];
int cur[30];
string a,b;
int n,m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	m = a.size();
	n = b.size();
	a = "0" + a;
	b = "0" + b;
	// nxt
	up(i,0,APHABET) cur[i] = m + 1;
	for(int i=m;i>=0;--i){
		for(int j=0;j<=APHABET;++j){
			nxt[i][j] = cur[j];
			if (a[i] == (char) (j + 'a')) cur[j] = i;
		}
	}
	for(int i=1;i<=n;++i){
		if (p[i-1] == m + 1) p[i] = m + 1;
		else p[i] = nxt[p[i-1]][b[i] - 'a'];
	}
	// prev 
	up(i,0,APHABET) cur[i] = 0;
	for(int i=1;i<=m+1;++i){
		for(int j=0;j<=APHABET;++j){
			prv[i][j] = cur[j];
			if (a[i] == (char) (j + 'a')) cur[j] = i;
		}
	}
	s[n+1] = m+1;
	// up(i,1,n) cout << b[i];
	for(int i=n;i>=1;--i){
		if (s[i+1] == 0) s[i] = 0;
		else {
			s[i] = prv[s[i+1]][b[i] - 'a'];
			if (s[i])	ans[s[i]] = max(ans[s[i]], n - i + 1);
		}
	}
	for(int i=m;i>=1;--i) ans[i] = max(ans[i], ans[i+1]);
	// up(i,1,n) cout << s[i] << ' '; cout << '\n';
	int res = 0;
	for(int i=0;i<=n;++i){
		if (p[i] != m + 1){
			res = max(res, min(n, i + ans[p[i] + 1]));
		}
	}
	if (res == 0) {
		cout << '-';
		return 0;
	}
	for(int i=0;i<=n;++i){
		if (p[i] != m + 1 && res == min(n, i + ans[p[i] + 1])){
			if (res == n) up(i,1,n) cout << b[i];
			else {
				up(j,1,i) cout << b[j];
				up(j,n - ans[p[i] + 1] + 1, n) cout << b[j];
			}
			return 0;
		}
	}
	// cout << res;
}