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
const int N = 105;
int t,n;
string s;
int p[N];
int solve(string s){
	n = s.size();
	for(int i=1;i<s.size();++i){
		int j = p[i-1];
		while (j > 0 && s[i] != s[j]) j = p[j-1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	return (n % (n - p[n-1]) == 0 ? (n - p[n-1]) : n);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("solve.inp","r", stdin);
	// freopen("solve.out","w", stdout);
	cin >> t;
	while (t--){
		cin >> s;
		cout << solve(s) << '\n';
		if (t) cout << '\n';
 	}
}
