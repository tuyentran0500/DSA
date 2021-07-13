#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define sp pair<pr, int>
using namespace std;
const int N  = 85;
int a[N][N], b[N][N];
bool ok[N][N][2*N*N + 5];
int ox[] = {0,1};
int oy[] = {1,0};
int h,w;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w;
	up(i,1,h) up(j,1,w) cin >> a[i][j];
	up(i,1,h) up(j,1,w) cin >> b[i][j];
	queue<sp> q;
	q.push({{1, 1}, N*N});
	ok[1][1][N*N] = 1;
	int ans = INT_MAX;
	while (q.size()){
		int x = q.front().first.first, y = q.front().first.second,
			dis = q.front().second;
		q.pop();
		if (x == h && y == w){
			ans = min(ans, abs(dis + a[x][y] - b[x][y] - N * N));
			ans = min(ans, abs(dis - a[x][y] + b[x][y] - N * N));
		}
		dis += a[x][y] - b[x][y];

		for(int d = 0; d < 2; ++d){
			int nx = x + ox[d], ny = y + oy[d];
			if (nx > h || !nx || ny > w || !ny) continue;
			if (!ok[nx][ny][dis]){
				ok[nx][ny][dis] = 1;
				q.push({{nx, ny}, dis});
			}
		}
		dis -= 2*(a[x][y] - b[x][y]);
		for(int d = 0; d < 2; ++d){
			int nx = x + ox[d], ny = y + oy[d];
			if (nx > h || !nx || ny > w || !ny) continue;
			if (!ok[nx][ny][dis]){
				ok[nx][ny][dis] = 1;
				q.push({{nx, ny}, dis});
			}
		}
	}
	cout << ans;
}