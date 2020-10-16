/*input
 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2005;
map<pr,int> cnt;
int n;
pr point[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> point[i].first >> point[i].second;
	}
	long long ans = 0;
	sort(point+1,point+1+n);
	up(i,1,n){
		up(j,1,i-1){
			int y = point[i].second - point[j].second, 
				x = point[i].first - point[j].first;
			ans += cnt[{x, y}]++;
		}
	}
	cout << ans/2;
}