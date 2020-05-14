/*input

*/
// https://codeforces.com/contest/1350/problem/E
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 1005;
ll step[N][N];
int ok[N][N];
int n,m,t;
int ox[] = {1, -1, 0, 0};
int oy[] = {0, 0, -1,1};
bool check(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;cin >> c;
			ok[i][j] = c - '0';
			step[i][j] = 2e18;
		}
	}
	queue<pr> q;
	for(int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			for(int z = 0; z < 4; ++z){
				int ni = i + ox[z], nj = j + oy[z];
				if (!check(ni,nj)) continue;
				if (ok[i][j] == ok[ni][nj]){
					step[i][j] = 0;
					q.push(pr(i,j));
					break;
				}
			}
		}
	}
	while (q.size()){
		pr u = q.front();	q.pop();
		int x = u.first, y = u.second;
		for(int i=0;i<4;++i){
			int nx = x + ox[i], ny = y + oy[i];
			if (!check(nx,ny) || step[nx][ny] <= step[x][y] + 1) continue;
			step[nx][ny] = step[x][y] + 1;
			q.push(pr(nx,ny));
		}
	}
	while (t--){
		int x,y;ll p; cin >> x >> y >> p;
		p = (p < step[x][y] ? 0 : (p-step[x][y]) % 2);
		cout << (p ? !ok[x][y] : ok[x][y]) << '\n';

	}
}