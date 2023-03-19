/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 8;
map<long long, bool> used;
char s[N][N];
#define pos(i,j) ((i) * (n) + j)
int n,k; 
int ox[4] = {1, -1, 0, 0};
int oy[4] = {0, 0, 1, -1};
long long state = 0;
long long ans = 0; 
void dfs(int x, int y, int r){
	if (!r) {
		ans += (used[state] == 0);
		used[state] = 1;
		return;
	}
	for(int i=0;i<4;++i){
		int nx = x + ox[i], ny = y + oy[i];
		if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
		if (s[nx][ny] == '.'){
			s[nx][ny] = '@';
			state += (1 << pos(nx, ny));
			dfs(nx, ny, r - 1);
			state -= (1 << pos(nx, ny));
			s[nx][ny] = '.';
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin >> s[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if (s[i][j] == '.'){
				state = (1 << pos(i,j));
				s[i][j] = '@';
				dfs(i, j, k - 1);
				s[i][j] = '.';
			}
		}
	}
	cout << ans;
}