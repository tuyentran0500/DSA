/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
bool dp[N][2];
vector<int> G[N];
int ok[N];
int n,m,s;
pr pre[N][2];
bool isCycle;
// check if cycle exists
// super bugs: `bool ok[N]` 

void dfs(int u){
	ok[u] = 1;
	for(auto v : G[u]){
		if (!ok[v]){
			dfs(v);
		}
		else {
			if (ok[v] == 1) isCycle = 1;
		}
	}
	ok[u] = 2;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(u,1,n){
		int k; cin >> k;
		while (k--){
			int v; cin >> v;
			G[u].push_back(v);
		}
	}
	cin >> s;
	dp[s][0] = 1;
	queue<pr> q;
	q.push({s, 0});
	while (q.size()){
		int u = q.front().first, state = q.front().second; q.pop();
		for(auto v : G[u]){
			if (!dp[v][!state]){
				pre[v][!state] = {u, state};
				q.push({v, !state});
				dp[v][!state] = 1;
			}
		}
	}
	for(int i=1;i<=n;++i) if (!G[i].size() && dp[i][1]) {
		cout << "Win\n";
		vector<int> ans;
		int u = i, state = 1;
		// bugs: Note to trace from the answer 
		while (u != s || state){
			ans.push_back(u);
			pr node = pre[u][state];
			u = node.first;
			state = node.second;
		}
		ans.push_back(s);
		reverse(ans.begin(), ans.end());
		for(auto v : ans) cout << v << ' ';
		cout << '\n';
		return 0;
	}
	dfs(s);
	if (isCycle) cout << "Draw";
	else cout << "Lose";
}	