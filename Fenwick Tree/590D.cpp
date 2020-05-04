/*input
abacaba
5
2 1 4
1 4 b
1 5 b
2 4 6
2 1 7
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 100005;
int bit[30][N];
int n;
void upd(int t, int u,int val){
	while(u <= n) {
		bit[t][u]+=val;
		u+=(u&-u);
	}
}
int get(int t,int u){
	int ans = 0;
	while(u){
		ans += bit[t][u];
		u-=(u&-u);
	}
	return ans;
}
string s;
int q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.size();
	for(int i=0;i<s.size();++i) upd(s[i]-'a',i+1,1);
	cin >> q;
	while(q--){
		int t,l,r,pos; char c;
		cin >> t;
		if (t == 1){
			cin >> pos >> c; 
			upd(s[pos-1]-'a',pos,-1);
			s[pos-1] = c;
			upd(s[pos-1]-'a', pos, 1);
		}
		else {
			cin >> l >> r;
			int ans = 0;
			for(int i=0;i<='z'-'a';++i) ans += (get(i,r) - get(i,l-1) != 0);
			cout << ans << '\n';
		}
	}
}