/*input
7 8
1 2
1 3
2 4
3 5
3 6
4 7
5 7
6 7
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 605;
long double E[N];
bool ok[N];
vector<int> G[N];
int n,m;
long double ans = 1005;
void solve(int block){
	E[n] = 0;
	for(int u=n-1;u>=1;--u){
		long double sum = 0, maxChild = 0;
		int num = G[u].size();
		for (auto v : G[u]){
			sum += E[v];
			maxChild = max(maxChild, E[v]);
		}
		if (u == block && num >= 2){
			sum-=maxChild;
			num--;
		}
		E[u] = sum/num + 1;
	}
	ans = min(ans, E[1]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
	}
	for(int i=0;i<n;++i) solve(i);
	cout << fixed << setprecision(6) << ans;
	// dfs(1);
}