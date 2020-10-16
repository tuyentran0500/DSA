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
int p[N][2], sz[N][2];
int n;
vector<int> G[N];
void init(){
	up(i,1,n) up(j,0,1) p[i][j] = i, sz[i][j] = 1;
}
int finds(int u,int c){
	return (p[u][c] == u ? u : p[u][c] = finds(p[u][c], c));
}
void joins(int u,int v,int c){
	int paru = finds(u, c), parv = finds(v, c);
	if (paru != parv){
		p[paru][c] = parv;
		sz[parv][c] += sz[paru][c];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	init();
	up(i,2,n){
		int u,v,c; cin >> u >> v >> c;
		joins(u,v,c);
	}
	long long ans = 0;
	up(i,1,n){
		if (i == p[i][0]) ans += 1LL * sz[i][0] * (sz[i][0] - 1);
		if (i == p[i][1]) ans += 1LL * sz[i][1] * (sz[i][1] - 1);
		ans += 1LL * (sz[finds(i,0)][0] - 1) * (sz[finds(i,1)][1] - 1);
	}
	cout << ans;
}