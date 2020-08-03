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
const int N = 2005;
vector<int> G[N];
int ans[N];
int d[N];
int n;
int bfs(int src){
	queue<int> q;
	for(int i=1;i<=n;++i) d[i] = INT_MAX;
	q.push(src);
	d[src] = 0;
	while (q.size()){
		int u = q.front(); q.pop();
		for (auto v : G[u]){
			if (v == src){
				return d[u] + 1;
			}
		} 
		for (auto v : G[u]){
			if (d[v] > d[u] + 1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			int val; cin >> val;
			if (val) G[i].push_back(j);
		}
	}
	up(i,1,n){
		int ans = bfs(i);
		if (ans == -1) cout << "NO WAY" << '\n';
		else cout << ans << '\n';
	}
}
```
5
0 1 1 1 1
1 0 0 0 1
0 0 1 1 0
0 0 1 0 0
0 0 0 1 0
```  
h[1,2] = 1