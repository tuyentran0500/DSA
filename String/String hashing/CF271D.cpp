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
const int N = 1505; 
int mod[2] = {1000000007, 1000000009};
long long h[2][N], base[2][N];
set<pr> ans;
string s;
string ok;
int n,k;
long long get(int t,int l,int r){
	return (h[t][r] - h[t][l-1] * base[t][r-l+1] + 1ll*mod[t]*mod[t]) % mod[t];
}
void init(){
	n = s.size();
	base[0][0] =  base[1][0] = 1;
	for(int i=1;i<=n;++i) {
		base[0][i] = (base[0][i-1] * 30) % mod[0];
		base[1][i] = (base[1][i-1] * 30) % mod[1];
	}
	for(int i=0;i<n;++i){
		up(j,0,1) h[j][i+1] = (h[j][i] * 30 + s[i] - 'a' + 1) % mod[j];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> ok >> k;
	init();
	for(int i=1;i<=n;++i){
		int cnt = 0;
		for(int j=i;j<=n;++j){
			cnt += (ok[s[j-1]-'a'] == '0');
			if (cnt > k) break;
			ans.insert(pr(get(0,i,j), get(1,i,j)));
		}
	}
	cout << ans.size();
}