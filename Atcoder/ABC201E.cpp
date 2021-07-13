#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,long long>
using namespace std;
const int N  = 200005;
const int mod = 1e9 + 7;

long long dis[N];
int cnt[60][2];
vector<pr> G[N];
int n;
void dfs(int u, int pre){
	for(auto [v,w] : G[u]){
		if (v == pre) continue;
		dis[v] = dis[u] ^ w;
		dfs(v,u);
	}
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
	up(i,2,n){
		int u,v; long long w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1,0);
	long long ans = 0;

	up(i,1,n){
		for(int j=0;j<60;++j){
			cnt[j][bits(dis[i], j)]++;
			ans = (ans + (1LL << j) % mod * cnt[j][!bits(dis[i], j)]) % mod;
		}
	}
	cout << ans;
}