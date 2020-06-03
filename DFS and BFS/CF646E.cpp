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
const int N = 200005;
int a[N], b[N], c[N];
int n;
vector<int> G[N];
bool ok[N];
long long ans;
pr dfs(int u,int minVal){
	ok[u] = 1;
	minVal = min(minVal, a[u]);
	pr res = pr(0,0);
	if (b[u] != c[u]) {
		res.first += b[u];
		res.second += (!b[u]);
	}
	for(auto v : G[u]){
		if (!ok[v]){
			pr done = dfs(v, minVal);
			res.first += done.first;
			res.second += done.second;
		}
	}
	int addition_pr = min(res.first, res.second);
	ans += 1LL * addition_pr * 2 * minVal;
	res.first -= addition_pr;
	res.second -= addition_pr;
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i] >> b[i] >> c[i];
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	pr res = dfs(1, INT_MAX);
	if (res != pr(0,0)) cout << -1;
	else cout << ans << '\n';
}
