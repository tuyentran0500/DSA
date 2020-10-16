/*input
*/
// Call d[u] is the minimum number of apple that make subtree u balance.  
// we can calculate d[u] = LCM(d[v1], d[v2], d[vn]) * n with v1,v2..vn is the child of node u.  
// After caculate d[1], we redistribute the value d[v] = d[u] / num_child[u] with v is the child of u.  
// We realize that the answer will be the multiple of the value of d[u].
// --> ans = sum[1] - d[1] * min(sum[u]/ d[u]) 
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 100005;
const ll INF = (1LL << 60);
ll d[N], sum[N];
bool overflow = false;
ll cnt[N];
int n;
vector<int> G[N];
ll lcm(ll a,ll b){
	if (a >= INF/b) {
		overflow = 1;
		return INF;
	} 
	return a * b / __gcd(a,b);
}
void dfs(int u,int pre){
	// cerr << u << ' ' << pre << '\n';
	for(auto v : G[u]){
		if (v == pre) continue;
		dfs(v,u);
		cnt[u]++;
		sum[u] += sum[v];
	}	
	ll LCM = 1;
	if (!cnt[u]) {
		d[u] = 1;
		return;
	}
	for(auto v : G[u]){
		if (v == pre) continue;
		if (!overflow) LCM = lcm(LCM, d[v]);
	}
	if (!overflow){
		if (LCM >= INF/cnt[u]) {
			overflow = true;
			LCM = INF;
		}
		else LCM *= cnt[u];
	}
	d[u] = LCM;
}
void reDFS(int u,int pre){
	for(auto v : G[u]){
		if (v == pre) continue;
		d[v] = d[u] / cnt[u];
		reDFS(v, u);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> sum[i];
	up(i,2,n){
		int u,v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	reDFS(1, 0);
	if (overflow){
		cout << sum[1];
		return 0;
	}
	ll res = INF;
	up(u,1,n) res = min(res, sum[u]/d[u]);
	cout << sum[1] - d[1] * res;
}