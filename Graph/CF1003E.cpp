/*input

*/
// https://codeforces.com/contest/1003/problem/E
#include <bits/stdc++.h>
#define pr pair<int,int>

using namespace std;
const int N = 400005;
const int INF = 1e15;
vector<int> G[N];
int n,d,k;
int curNode = 1;
int root;
vector< pr > ans;
void dfs(int u,int par, int depth, int ok){
	if (depth + ok <= (d/2)){
		while (curNode < n && G[u].size() < k){
			G[u].push_back(++curNode);
			G[curNode].push_back(u);
		}
	}
	for(auto v : G[u]){
		if (v == par) continue;
		// cout << u << ' ' << v << '\n';
		ans.push_back({u, v});
		dfs(v, u, depth + 1, (v != root - 1  || d % 2 == 0) && ok);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d >> k;
	if (k == 1){
		if (n == 2 && d == 1) cout << "YES\n1 2";
		else cout << "NO\n";
		return 0;
	}
	for(int i=1;i<=d;++i){
		G[curNode].push_back(curNode + 1);
		G[curNode+1].push_back(curNode);
		curNode++;
	}
	root = 1 + (d + 1)/2;
	dfs(root,0, 0,1);
	if (ans.size() + 1 != n) cout << "NO";
	else {
		cout << "YES\n";
		for(int i=0;i<ans.size();++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	
}