/*input

*/
// https://atcoder.jp/contests/arc099/tasks/arc099_b
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define ll long long
#define pr pair<int,int>
using namespace std;
int k;
ll S(ll n){
	string s = to_string(n);
	int ans = 0;
	for(auto c : s) ans += c - '0';
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	ll cur = 1, add = 1;
	cout << 1 << '\n';
	for(int i=2;i<=k;++i){
		ll nxt = cur + add;
		ll nxt2 = nxt + add;
		if (nxt*S(nxt2) > nxt2*S(nxt)) { // nxt/S(nxt) > nxt2/S(nxt2) --> change to the next digit. 
			add *= 10;
			nxt = cur + add;
		}
		cur = nxt;
		// cur = nxt;
		cout << cur << '\n';
	}
}