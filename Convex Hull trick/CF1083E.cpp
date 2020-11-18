/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1000005;
#define int long long
#define sp pair<pr, int> 
#define X first.first
#define Y first.second
#define val second
int n;
sp a[N];
vector< sp > important;
long double slope(pr l1, pr l2){
	return 1.0 * (l2.second - l1.second)/(l2.first - l1.first);
}
bool bad(pr l1, pr l2, pr l3){
	return slope(l1, l3) < slope(l1, l2);
}
vector<pr> line;
int dp[N];
void add(pr u){
	while (line.size() >= 2){
		#define last line.size() - 1
 		if (bad(line[last-1], line[last], u)) line.pop_back();
 		else break;
	}
	line.push_back(u);
}
int cnt;
int f(int x, pr u){return u.first * x + u.second; }
int query(int x){
	#define sz line.size()
	if (cnt >= sz) cnt = sz - 1;
	while (cnt + 1 < sz && f(x, line[cnt]) < f(x, line[cnt+1])) cnt++;
	return f(x, line[cnt]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> a[i].X >> a[i].Y >> a[i].val;
	}
	sort(a+1,a+1+n);
	// increasing in x_i
	// decreasing in y_i.
	important.push_back({{0, 1e9}, 0});
	for(int i=1;i<=n;++i){
		while (important.back().Y < a[i].Y) important.pop_back();
		important.push_back(a[i]);
	}
	line.push_back({0, 0});
	// dp[i] = max(dp[j] - y_i * x_j + y_i * x_i - a[i]
	//               b       x * a     
	int ans = 0;
	for(int i=1;i<important.size();++i){
		dp[i] = query(important[i].Y) + important[i].X * important[i].Y - important[i].val;
		add({-important[i].X, dp[i]});
		ans = max(ans, dp[i]);
	}
	cout << ans;
}