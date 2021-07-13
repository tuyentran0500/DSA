#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 1005;
int d[N][N];
vector<int> G[N][30];
int n,m;
int ans = INT_MAX;
void bfs(){
	up(i,1,n) up(j,1,n) d[i][j] = INT_MAX;
	d[1][n] = 0;
	queue<pr> q;
	q.push({1,n});
	while (q.size()){
		int u = q.front().first, v = q.front().second; q.pop();
		if (u == v) {
			ans = min(ans, d[u][v]);
			continue;
		}
		if (d[u][v] > ans) return;
		for(int c = 0; c <= 'z' - 'a'; ++c){
			for(auto nxtu : G[u][c]){
				for(auto nxtv : G[v][c]){
					if (nxtu == v && nxtv == u) {
						ans = min(ans, d[u][v] + 1);
					}
					if (d[nxtu][nxtv] > d[u][v] + 2){
						d[nxtu][nxtv] = d[u][v] + 2;
						q.push({nxtu, nxtv});
					}
				}
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v; char w; cin >> u >> v >> w;
		G[v][w - 'a'].push_back(u);
		G[u][w - 'a'].push_back(v);
	}
	bfs();
	cout << (ans == INT_MAX ? -1 : ans);
}