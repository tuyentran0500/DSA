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
string s,b;
int cur[N];
void solve(){
	int m = b.size();
	int curP = 0;
	s = b + "#" + s;
	for(int i=1;i<s.size();++i){
		int j = curP;
		while (j > 0 && s[i] != s[j]) 
			j = cur[j-1];
		if (s[i] == s[j]) j++;
		curP = j;
		if (i <= m) cur[i] = curP;
		if (curP == m) cout << i - 2*m + 1 << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> b;
	solve();
} 