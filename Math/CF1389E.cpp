/*input

*/
// https://codeforces.com/contest/1389/problem/E
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
int t;
int m,d,w;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> m >> d >> w;
		int w2 = w / __gcd(d-1, w);
		int mn = min(d, m);
		int cnt = mn / w2;

		cout << 1LL * mn * cnt - 1LL*cnt*(cnt+1)*w2/2 << '\n'; 
	}

}