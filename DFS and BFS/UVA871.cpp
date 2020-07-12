/*input
2

01
10

001
110
001
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 26;
int ok[N][N];
int ox[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int oy[] = {-1, -1,-1, 0 , 0, 1, 1, 1};
int ans = 0;
string c[N];
int t,n,m;
bool check(int x, int y){
	return (x >= 0 && y >= 0 && x < n  && y < m);
}
void bfs(int x, int y){
	queue< pair<int,int> > q;
	q.push({x, y}); // {x, y} --> tạo 1 pair. 
	int connectedElements = 1; ok[x][y] = 1;
 	while (q.size() != 0){
		pair<int,int> u = q.front(); q.pop();
		int x = u.first;	
		int y = u.second;
		for(int i=0;i<8;++i){
			int nx = x + ox[i];
			int ny = y + oy[i];
			// (nx, ny) là 1 đỉnh kề với đỉnh (x,y).
			if (check(nx,ny) == false || c[nx][ny] != '1' || ok[nx][ny]) continue;
			q.push({nx, ny});
			connectedElements++;
			ok[nx][ny] = 1;
		}
	}
	ans = max(ans, connectedElements);
}
string s;
int main(){
	ios_base::sync_with_stdio(0); 
	freopen("solve.inp","r", stdin);
	// freopen("solve.out","w", stdout);
	cin >> t; 
	getline(cin, s);
	getline(cin, s);
	while (t--){
		memset(ok, 0, sizeof(ok));
		n = 0;
		ans = 0;
		while (getline(cin , c[n])){
			if (c[n] != "") n++;
			else break;
		}
		m = c[0].size();
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if (!ok[i][j] && c[i][j] == '1'){
					bfs(i, j);
				}
			}
		}
		cout << ans << '\n';
		if (t != 0) cout << '\n';
	}
}
