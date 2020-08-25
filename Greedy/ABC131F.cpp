/*input
5
0 0
0 1
1 0
2 2
3 1
*/
// clean code
#include <bits/stdc++.h>
#define pr pair<int,int>
#define val(u,t) (u + (t == 0 ? 0 : N))
using namespace std;
const int N = 1e5 + 5;
int n;
bool ok[2*N];
pr point[N];
vector<int> Gx[N], Gy[N];
void dfs(int u, int& xPoint, int& yPoint,bool t){
	if (!t){
		for (auto y : Gx[u]){
			if (!ok[val(y, 1)]){
				ok[val(y,1)] = 1;
				dfs(y, xPoint, ++yPoint,1);
			}
		}
	}
	else{
		for (auto x : Gy[u]){
			if (!ok[val(x, 0)]){
				ok[val(x,0)] = 1;
				dfs(x, ++xPoint, yPoint,0);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		int x,y; cin >> x >> y;
		point[i] = {x, y};
		Gx[x].push_back(y);
		Gy[y].push_back(x);
	}
	long long ans = 0;
	for (int i=1;i<=n;++i){
		if (!ok[val(point[i].first,0)]) {
			#define x point[i].first
			#define y point[i].second
			int xPoint = 1, yPoint = 0;
			ok[val(x, 0)] = 1;
			dfs(x,xPoint, yPoint, 0);
			// cout << xPoint << ' ' << yPoint << ' ' << cnt << '\n';
			ans += 1LL * xPoint * yPoint;
		}
	}
	cout << ans - n;
}