/*input
qwertyqwertyqwerty
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
int z[N];
string s;
void solve(){
	int n = s.size();
	int l = 0, r = 0;
	for(int i=1;i<n;++i){
		if (i <= r)
			z[i] = min(z[i-l], r-i+1);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	int ans = 0;
	set<int> v;
	for(int i=1;i<n;++i){
		v.insert(z[i] - (i + z[i] == n));
	} 
	for(int i=n-1;i>=1;--i){
		if (z[n-i] == i){
			set<int>::iterator it = lower_bound(v.begin(), v.end(),i);
			if (it != v.end()) {
				ans = i; 
				break;
			}
		}
	}
	if (ans == 0) cout << "Just a legend";
	else {
		for(int i=0;i<ans;++i) cout << s[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	solve();
}