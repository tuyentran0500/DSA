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
const int N = 2000005;
string p,t; 
int z[N];
void solve(){
	z[0] = 0;
	int l = 0, r = 0;
	int n = t.size();
	for(int i=1;i<n;++i){
		if (i <= r)
			z[i] = min(r-i+1, z[i-l]);
		while (i + z[i] < n && t[z[i]] == t[i+z[i]]) z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
		if (z[i] == p.size()) cout << i - p.size() << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t >> p;
	t = p + "#" + t;
	solve();
}