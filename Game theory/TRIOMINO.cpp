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
const int N = 1605;
int cnt[N],n,t;
int g[N], mex[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;	n*=2;
		g[0] = g[1] = g[2] = 0;
		for(int i=3;i<=n;++i){
			memset(cnt, 0, sizeof(cnt));
			for(int j=0;j+3 <= i;++j){
				cnt[g[j] ^ g[i - 3 -j]] = 1;
			}
			for(int j=0;j<N;++j) if (!cnt[j]) {g[i] = j; break;}
		}
		cout << (g[n] ? "X" : "Y")<< '\n';
	}
 }