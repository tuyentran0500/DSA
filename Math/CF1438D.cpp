/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int a[N], n;
#define sp pair<int,pr>
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int xorSum = 0;
	up(i,1,n) cin >> a[i], xorSum ^= a[i];
	if (n % 2 == 0 && xorSum != 0) {cout << "NO"; return 0;}
	cout << "YES\n";
	vector< sp > ans;
	if (n & 1){
		for(int i=1;i+2<=n;i+=2) ans.push_back({i, {i+1, i+2}});
		for(int i=n-2;i>=3;i-=2) ans.push_back({i, {i-1, i-2}});
	}
	else {
		for(int i=1;i+2<=n;i+=2) ans.push_back({i, {i+1, i+2}});
		ans.push_back({n-2, {n-1, n}});
		for(int i=n-3;i>=3;i-=2) ans.push_back({i, {i-1, i-2}});
	}
	cout << ans.size() << '\n';
	for(auto node : ans) cout << node.first << ' ' << node.second.first << ' ' << node.second.second << '\n';
}