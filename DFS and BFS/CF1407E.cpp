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
const int N = 500005;
vector< pr > P[N];
int n,m;
bool ok[N][2];
int d[N], ans[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int u,v,c; cin >> u >> v >> c;
		P[v].push_back({u, c});
	}
	queue<int> q;
	ok[n][0] = ok[n][1] = true;
	q.push(n);
	while (q.size()){
		int u = q.front(); q.pop();
		for (auto node : P[u]){
			int v = node.first, c = node.second;
			if (!ok[v][c]){
				ok[v][c] = 1;
				if (ok[v][!c]){
					d[v] = d[u] + 1;
					q.push(v);
				}
				else ans[v] = !c;
			}
		}
	}
	cout << (ok[1][ans[1]] ? d[1] : -1) << '\n';
	up(i,1,n) cout << ans[i];
}