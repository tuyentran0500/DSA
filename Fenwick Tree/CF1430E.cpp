/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 200005;
int b[N], n;
void upd(int u,int val){
	while (u <= n){
		b[u] += val;
		u += (u&-u);
	}
}
int get(int u){
	int ans = 0;
	while (u > 0){
		ans += b[u];
		u -= (u & -u);
	}
	return ans;
}
string s;
vector<int> cnt[30];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("solve.inp","r", stdin);
	cin >> n >> s;
	for(int i=0;i<n;++i){
		cnt[s[i] - 'a'].push_back(i + 1);
	}
	reverse(s.begin(), s.end());
	for(char c = 'a'; c<= 'z';++c) reverse(cnt[c - 'a'].begin(), cnt[c - 'a'].end());
	up(i,1,n) upd(i,1);
	long long ans = 0;
	for(int i=0;i<n;++i){
		ans += get(cnt[s[i] - 'a'].back() - 1);
		upd(cnt[s[i] - 'a'].back(), -1);
		cnt[s[i] - 'a'].pop_back();
	}
	cout << ans;
}