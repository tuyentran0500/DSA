/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 105;
char c[N][N];
int ver, hor, square;
int n, m;
// (x1, y1)    (y2)
//
// (x2)
char get(int x,int y){
	char usedC = 'a';
	for(usedC = 'a'; usedC <= 'e'; ++usedC){
		if (usedC == c[x-1][y] || usedC == c[x][y+1]
		|| usedC == c[x-1][y-1] || usedC == c[x+1][y+1]) continue;
		else break;
	}
	return usedC;
}
bool solve(int x1,int y1,int x2,int y2){
	int w = y2 - y1 + 1, h = x2 - x1 + 1;
	if (h == 0 || w == 0) return true;
	if ((h * w) & 1) return false;
	// cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	if (h & 1){
		// use horizontal planks
		if (w/2 > hor) return false;
		hor -= w/2;
		for(int posy = y2; posy >= y1;posy-=2) c[x1][posy] = c[x1][posy-1] = get(x1, posy);
		return solve(x1 + 1, y1, x2, y2);
	}
	if (w & 1){
		if (h / 2 > ver) return false;
		ver -= h/2;
		for(int posx = x1; posx <= x2; posx += 2) c[posx][y2] = c[posx+1][y2] = get(posx, y2);
		return solve(x1, y1, x2, y2 - 1);
	}
	if (h * w > 2*ver + 2*hor + 4*square) return false;
	// cout << ver << ' ' << hor << ' ' << square << '\n';
	for(int x = x1; x <= x2; x+=2){
		for(int y = y2; y >= y1; y-=2){
			if (square){
				c[x][y] = c[x+1][y] = c[x][y-1] = c[x+1][y-1] = get(x, y);
				square--;
			}
			else if (hor >= 2){
				// use horizontal plank.
				// (x,y-1) (x,y) 
				c[x][y] = c[x][y - 1] = get(x, y);
				c[x+1][y] = c[x+1][y-1] = get(x+1, y) ;
				hor-=2;
			}
			else if (ver >= 2) {
				// use vertical plank.
				c[x][y] = c[x+1][y] = get(x, y);
				c[x][y-1] = c[x+1][y-1] = get(x, y-1);
				ver-=2;
			}
			else return false;
		}
	}
	return true;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cin >> hor >> ver >> square;
	if (solve(1,1,n,m)){
		up(i,1,n) {
			up(j,1,m) cout << c[i][j];
			cout << '\n';
		}
	}
	else cout << "IMPOSSIBLE";
}