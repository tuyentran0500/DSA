/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
vector<int> G[N];
int farthest[N];
int d[N], n;
int dp[N];
int findRoot(int u,int pre){
	int ans = u;
	for(auto v : G[u]){
		if (v == pre) continue;
		d[v] = d[u] + 1;
		int cur = findRoot(v, u);
		if (d[ans] < d[cur]) ans = cur;
	}
	return ans;
}
int maxDistance(int u){
	return d[farthest[u]] - d[u];
}
int father[N];
int dfs(int u,int pre){
	int ans = u;
	for(auto v : G[u]){
		if (v == pre) continue;
		d[v] = d[u] + 1;
		father[v] = u;
		int cur = dfs(v, u);
		if (d[ans] < d[cur]) ans = cur;
	}
	return farthest[u] = ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,2,n) {
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int root = findRoot(1, 0); d[root] = 0;
	dfs(root, 0);
	priority_queue<pr> pq;
	pq.push({maxDistance(root), root});
	// for(int i=1;i<=n;++i) cout << i << ' ' << maxDistance(i) << ' ' << farthest[i] << '\n';
	// return 0;
	int k = 1;
	while (pq.size()){
		int u = pq.top().second; pq.pop();
		dp[k+1] = dp[k] + maxDistance(u) + 1; k++;
		int curNode = farthest[u];
		if (curNode == u) continue;
		do {
			int prevNode = curNode;
			curNode = father[curNode];
			for(auto v : G[curNode]){
				if (v == prevNode || v == father[curNode]) continue;
				pq.push({maxDistance(v), v});
			}
		} while (curNode != u);
	}
	for(int i=k+1;i<=n;++i) dp[i] = n;
	for(int i=1;i<=n;++i) cout << (i == 1 ? 1 : dp[i]) << ' ';
}