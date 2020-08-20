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
const int K = 5;
int n,k;
int modNode[N][K], child[N];
long long ans = 0;
vector<int> G[N];
int subtract(int a,int b){
	return (a - b + k*10) % k;
}
void dfs(int u,int par,int depth){   
	modNode[u][depth % k] = child[u] = 1;
	for(auto v : G[u]){
		if (v == par) continue;
		dfs(v, u, depth+1);
		child[u] += child[v];
		for(int i=0;i<k;++i){
			for(int j=0;j<k;++j){
				int remainder = subtract(i+j, 2*depth);
				int add = subtract(k, remainder);
				ans += 1LL * add * modNode[u][i] * modNode[v][j];
			}
		}
		for(int i=0;i<k;++i) modNode[u][i] += modNode[v][i];
	}
	ans += 1LL * (n - child[u]) * child[u];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i=1;i<n;++i){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1,0);
	cout << ans / k << '\n';
}