/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N  = 200005;
map<string, vector<int>> edge;
vector<int> G[N];
int n;
string s[N];
int dp[N];
int isOdd[N];
// 0 lose
// 1 draw
// 2 win
int visited[N];
void dfs(int u, int odd){
	visited[u] = 1;
	isOdd[u] = odd;
	for(auto v : G[u]){
		if (!visited[v]){
			dfs(v,1 - odd);
			dp[u] = max(dp[u], 2 - dp[v]);
		}
		else if (visited[v] == 2){
			dp[u] = max(dp[u], 2 - dp[v]);
		}
		else {

			if (odd[dp[u] = max(dp[u], 1); // detect cycle

		}
	}
	if (G[u].size() == 0) dp[u] = 2;
	visited[u] = 2;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> s[i];
		edge[s[i].substr(0,3)].push_back(i);
	}
	up(u,1,n){
		int len = s[u].size();
		for(auto v : edge[s[u].substr(len - 3, 3)]){
			G[u].push_back(v);
		}
	}
	up(i,1,n){
		if (!visited[i]) dfs(i, 1);
		if (dp[i] == 0) cout << "Aoki\n";
		if (dp[i] == 1) cout << "Draw\n";
		if (dp[i] == 2) cout << "Takahashi\n";
	}

}