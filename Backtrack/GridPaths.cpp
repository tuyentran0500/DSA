/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 10;
string s;
bool ok[N][N];
string dir = "DRUL";
int ox[] = {1, 0, -1, 0};
int oy[] = {0, 1, 0, -1};
int ans = 0;
bool check(int x,int y){
	return (x >= 1 && x <= 7 && y >= 1 && y <= 7 && !ok[x][y]);
}
void backtrack(int i,int j,int w){
	if (w >= s.size()){
		ans++;
		return; 
	}
	if (i == 7 && j == 1) return; // Why ????
	if (ok[i-1][j] && ok[i+1][j] && !ok[i][j-1] && !ok[i][j+1]) return;
	if (ok[i][j+1] && ok[i][j-1] && !ok[i-1][j] && !ok[i+1][j]) return;
	ok[i][j] = 1;
	for(int id = 0; id < 4; ++id){
		int ni = i + ox[id], nj = j + oy[id];
		if (!check(ni, nj)) continue;
		if (s[w] != '?' && s[w] != dir[id]) continue;
		backtrack(ni, nj, w + 1);
	}
	ok[i][j] = 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<=8;++i){
		ok[i][0] = ok[0][i] = 1;
		ok[8][i] = ok[i][8] = 1;
	}
	cin >> s;
	backtrack(1,1,0);
	cout << ans;
}
