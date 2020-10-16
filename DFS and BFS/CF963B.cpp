/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
bool dp[N];
vector<int> ans;
vector<int> G[N];
int n,root;
// dp[u] == 1 if we can erase the subtree u.  
// dp[u] == (number of dp[v] == 1) % 2;
void dfs(int u,int pre){
	int cnt = 0;
	for(auto v : G[u]){
		if (v == pre) continue;
		dfs(v, u);
		cnt += (dp[v] == 1);
	}
	dp[u] = !(cnt & 1);
}
void trace(int u,int pre){
	for(auto v : G[u]){
		if (v == pre) continue;
		if (!dp[v]) trace(v, u);
	}
	cout << u << '\n';
	for(auto v : G[u]){
		if (v == pre) continue;
		if (dp[v]) trace(v, u);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(v,1,n){
		int u; cin >> u;
		if (!u) {
			root = v;
			continue;
		}
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(root,0);
	// up(i,1,n) cout << dp[i] << ' ';
	if (dp[root]){
		cout << "YES\n";
		trace(root, 0);
	}
	else cout << "NO\n";
}