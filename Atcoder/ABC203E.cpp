/*
4 2
2 4
4 3
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 200005;
map<int, set<int>> row;
map<pr, bool> ok;
map<int,bool> ans;
int n,m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m) {
		int x, y; cin >> x >> y;
		row[y].insert(x);
	}
	queue<pr> q;
	q.push({0, n});
	while (q.size()){
		int x = q.front().first, y = q.front().second; q.pop();
		// cout << x << ' ' << y << '\n';
		auto it = row[y].upper_bound(x);
		int nxtX = *it;
		if (it == row[y].end()) ans[y] = 1, nxtX = 2 * n + 1;
		it = row[y+1].upper_bound(x);
		if (it != row[y+1].end()){
			int nx = *it, ny = y + 1;
			if (nxtX >= nx && !ok[{nx, ny}]){
				ok[{nx, ny}] = 1;
				q.push({nx, ny});
			}
			if (nxtX > nx && !ok[{nx, y}]){
				ok[{nx, y}] = 1;
				q.push({nx, y});
			}
		}
		it = row[y-1].upper_bound(x);
		if (it != row[y-1].end()){
			int nx = *it, ny = y - 1;
			if (nxtX >= nx && !ok[{nx, ny}]){
				ok[{nx, ny}] = 1;
				q.push({nx, ny});
			}
			if (nxtX > nx && !ok[{nx, y}]){
				ok[{nx, y}] = 1;
				q.push({nx, y});
			}
		}
	}
	cout << ans.size();
}