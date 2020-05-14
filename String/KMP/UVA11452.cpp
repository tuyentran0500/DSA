/*input
1
412412222341234123111231412131212121241241222234123412311123141213121212124124122223412341231112314122
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 2005;
const int mod = 1e9 + 9;
ll h[N], base[N];
int t,n;
string s;
ll get(int l,int r){
	if (l > r) return 0;
	return (h[r]  - h[l-1] * base[r-l+1] + 1LL*mod*mod) % mod;
}
void solve(){
	n = s.size();
	h[0] = 0;
	for(int i=0;i<n;++i){
		h[i+1] = (h[i] * 7 + (s[i] - '0')) % mod; 
	}

	for(int i=2;i<=n;i+=2){
		int j = i/2;
		if (get(1,j) == get(j+1,i) && get(1,n-i) == get(i+1,n)){
			// cout << i << ' ' << get(1,j) << ' ' << get(i+1,n) << '\n';
			for(int z =n - i; z < n-i + 8;++z) cout << s[z % j];
			break;
		}
	}
	cout << "...\n";
}
void init(){
	base[0] = 1;
	for(int i=1;i<N;++i) base[i] = (base[i-1] * 7) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	cin >> t;
	while (t--){
		cin >> s;
		solve();
	}
}