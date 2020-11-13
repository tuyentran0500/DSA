/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
// meet in middle
const int N = 45;
set<int> G[N]; // cannot have
map<string, int> cnt;
int n, m;
void input(){
	cin >> n >> m;
	int cur = 0;
	set<int> conflict;
	for(int i=1;i<=n;++i){
		int t; cin >> t;
		if (t == 1) {
			for(auto u : conflict){
				for(auto v : conflict){
					if (u == v) continue;
					G[u].insert(v);
					G[v].insert(u);
				}
			}
			conflict.clear();
		}
		else {
			string s; cin >> s;
			if (!cnt[s]) cnt[s] = ++cur;
			conflict.insert(cnt[s] - 1); // 0-th index
		}
	}
	for(auto u : conflict){
		for(auto v : conflict){
			if (u == v) continue;
				G[u].insert(v);
				G[v].insert(u);
			}
		}
	// for(auto u : conflict) cout << u << ' '; cout << '\n';
	conflict.clear();
}
int ans[1 << 22];
bool check(int mask, int id,int maxBIT){
	for(int i=0;i<maxBIT;++i) {
		if (!bits(mask, i)) continue;
		for(auto v : G[i + id]) 
			if (v >= id && v - id < maxBIT && bits(mask, v - id)) return false;
	}
	return true;
}
void maximize(int& u,int v){ u = max(u, v); }
void solve(int maxBIT){
	for(int mask=1;mask < (1 << maxBIT); ++mask){
		if (check(mask, 0, maxBIT)) {
			ans[mask] = __builtin_popcount(mask);
		}
		for(int j=0;j<maxBIT;++j) if (!bits(mask, j)) maximize(ans[mask | (1 << j)], ans[mask]);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	solve(min(m, 22));
	if (m <= 22){
		cout << ans[(1 << m) - 1];
	}
	else {
		m -= 22;
		int res = 0;
		for(int mask = 0; mask < (1 << m); ++mask){
			if (!check(mask, 22, m)) continue;
			int restMask = (1 << 22) - 1;
			for(int u=0;u<m;++u) if (bits(mask, u)){
				for(auto v : G[u + 22]) if (v < 22 && bits(restMask, v)) restMask -= (1 << v);
			}
			maximize(res, ans[restMask] + __builtin_popcount(mask));
		}
		cout << res;

	}
}