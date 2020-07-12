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
vector<int> G[N];
long long ans = 0;
int n;
void dfs(int u,int par){
	if (u < par) ans += 1LL * u * (par - u);
	else ans += 1LL * (u - par) * (n - u + 1);
	for (auto v : G[u]){
		if (v != par){
			dfs(v, u);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n-1){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans;
}