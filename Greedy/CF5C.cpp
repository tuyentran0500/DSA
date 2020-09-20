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
string a;
int s[N], r[N], n;
int ans[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a;
	n = a.size();
	a = "0" + a;
	up(i,1,n){
		s[i] = s[i-1] + (a[i] == '(' ? 1 : -1);
	}
	r[n] = n;
	for(int i=n-1;i>=0;--i){
		int j;
		for(j=i+1;j <= n && s[j] > s[i];j = r[j] + 1);
		r[i] = j - 1;
	}
	s[n + 1] = 1e9;
	// up(i,1,n) cout << s[i] << ' '; cout << '\n';
	// up(i,1,n) cout << r[i] << ' '; cout << '\n';
	for(int i=n;i>=0;--i){
		if (s[r[i] + 1] == s[i]) ans[i] = ans[r[i] + 1] + r[i] - i + 1;
		else ans[i] = 0;
 	}
 	int res = 0, cnt = 1;
 	for(int i=0;i<n;++i){
 		if (!ans[i]) continue;
 		if (res < ans[i]) {
 			res = ans[i];
 			cnt = 1;
 		}
 		else if (res == ans[i]) cnt++;
 	}
 	cout << res << ' ' << cnt;

} 