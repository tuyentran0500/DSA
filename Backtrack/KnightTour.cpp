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
const int N  = 8;
static int ox[] = {1,1,2,2,-1,-1,-2,-2};
static int oy[] = {2,-2,1,-1,2,-2,1,-1};
int visited[N][N];
bool isInBoard(int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]);
}
int numOfMove(int x, int y){
	int count = 0;
	for(int i=0;i<N;++i){
		int cx = x + ox[i], cy = y + oy[i];
		if (isInBoard(cx, cy)) count++;
	}
	return count;
}
int pos = 0;
int solve(int x, int y){
	int nx = -1, ny = -1;
	visited[x][y] = ++pos;
	int minDeg = N + 1;
	int start = rand() % N;
	for(int count=0;count<N;++count){
		int i = (count + start) % N; 
		int cx = x + ox[i], cy = y + oy[i];
		if (isInBoard(cx, cy)){
			int c = numOfMove(cx, cy);
			if (c < minDeg){
				minDeg = c;
				nx = cx;
				ny = cy;
			}
		}
	}
	if (nx != -1) return solve(nx, ny);
	return (visited[x][y] == 64);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y; cin >> y >> x; 
    x--; y--;
	while (!solve(x, y)){
		pos = 0;
		memset(visited, 0, sizeof(visited));
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

