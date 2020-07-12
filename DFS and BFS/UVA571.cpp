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
const int N = 105;
int n,m;
int ok[N][N];
int ox[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int oy[] = {-1, -1,-1, 0 , 0, 1, 1, 1};
char c[N][N];
bool check(int x, int y){
	return (x >= 0 && y >= 0 && x < n  && y < m);
}
void bfs(int x, int y){
	queue< pair<int,int> > q;
	q.push({x, y}); // {x, y} --> tạo 1 pair.
 	while (q.size() != 0){
		pair<int,int> u = q.front(); q.pop();
		int x = u.first;	
		int y = u.second;
		for(int i=0;i<8;++i){
			int nx = x + ox[i];
			int ny = y + oy[i];
			// (nx, ny) là 1 đỉnh kề với đỉnh (x,y).
			if (check(nx,ny) == false || c[nx][ny] != '@' || ok[nx][ny]) continue;
			q.push({nx, ny});
			ok[nx][ny] = 1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		for(int i=0;i<n;++i) for(int j=0;j<m;++j) ok[i][j] = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j) cin >> c[i][j];
		}
		int ans = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if (ok[i][j] == 0 && c[i][j] == '@'){
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}