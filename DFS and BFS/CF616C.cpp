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
const int N = 1005;
int numComponent[N*N];
int ox[] = {1, -1, 0, 0};
int oy[] = {0, 0, 1, -1};
char a[N][N];
int n,m;
int classes[N][N]; // nut (x,y) đã được duyệt chưa.
int ans[N][N];
bool check(int nx,int ny){
	return (nx < 0 || nx >= n || ny < 0 || ny >= m);
}
void dfs(int x,int y, int id){
    classes[x][y] = id;
    numComponent[id]++;
    for (int i=0;i<4;++i){
        int nx = x + ox[i], ny = y + oy[i];
        if (check(nx,ny) || classes[nx][ny] || a[nx][ny] != '.') 
        	continue;
        dfs(nx, ny,id);
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> a[i][j];

	int cnt = 0;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
		if (!classes[i][j] && a[i][j] == '.') dfs(i, j, ++cnt);
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if (a[i][j] == '*'){
				set<int> s; 
				for(int z=0;z<4;++z){
					int nx = i + ox[z], ny = j + oy[z];
					if (check(nx,ny) || a[nx][ny] != '.') continue;
					s.insert(classes[nx][ny]);
				}
				for(auto u : s){
					ans[i][j] += numComponent[u];
				}
				cout << (ans[i][j] + 1) % 10;
			}
			else cout << ".";
		}
		cout << '\n';
	}
}