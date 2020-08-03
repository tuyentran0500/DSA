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
const int N = 300005;
int a[N], cnt[N], D[N];
int n;
int prefD[N], sufD[N];
int f[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i=0;i<=n;++i) D[cnt[i]]++;
	for(int i=1;i<=n;++i) prefD[i] = prefD[i-1] + D[i] * i;
	for(int i=n;i>=1;--i) sufD[i] = sufD[i+1] + D[i];
	for(int i=1;i<=n;++i){
		// cerr << prefD[i] << ' ' << sufD[i+1] << '\n';
		f[i] = (prefD[i] + sufD[i+1] * i)/i;
	}
	int curPos = n;
	up(k,1,n) {
		while (curPos >= 1 && f[curPos] < k) curPos--;
		if (f[curPos] >= k) cout << curPos << '\n';
		else cout << 0 << '\n';
	}
}