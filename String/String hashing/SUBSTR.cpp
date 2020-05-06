/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
const int N = 1000005, mod = 1e9 + 7;
long long h[N],hb;
long long base[N];
using namespace std;
int n,m;
string a,b;
void init(){
	cin >> a >> b;
	n = a.size();
	m = b.size();
	base[0] = 1;
	up(i,1,max(n,m)) base[i] = (base[i-1] * 30) % mod;  
	for(int i=0;i<a.size();++i){
		h[i+1] = (h[i] * 30 + a[i] - 'a' + 1) % mod; 
	}
	for(int i=0;i<b.size();++i){
		hb = (hb + (b[i] -'a' + 1)* base[m-i-1]) % mod;
	}
}
long long get(int l,int r){
	return (h[r] - h[l-1]*base[r-l+1] + 1LL*mod*mod) % mod;
}
void solve(){
	for(int i=1;i+m-1<=n;++i){
		if (get(i,i+m-1) == hb) cout << i << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	solve();
}