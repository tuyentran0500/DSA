/*input
 
*/
// CF319C
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define int long long
#define pr pair<int,int>
using namespace std;
const int N = 100005;
 
int n, a[N], b[N];
int dp[N];
vector<pr> line;
long double slope(pr u, pr v){
	return 1.0 * (u.first - v.first)/(u.second - v.second);
}
bool bad(pr l1,pr l2, pr l3){
	// on the left side
	return slope(l1, l3) < slope(l1, l2);
}
void add(int a,int b){
	pr u = {a, b};
	while (line.size() > 1){
		#define last line.size() - 1
		if (bad(line[last-1], line[last], u)) line.pop_back();
		else break;
	}
	line.push_back(u);
}
int f(int x, pr u){ return x * u.first + u.second; }
int query(int x){
	static int cur = 0;	
	int sz = line.size();
	if (cur >= sz) cur = sz - 1;
	while (true){
		if (cur + 1 < sz && f(x, line[cur+1]) < f(x, line[cur])) cur++;
		else break;
	}
	return f(x, line[cur]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n) cin >> b[i];
	dp[1] = 0;
	// dp[i] = min(dp[j] + b[j] * a[i]);
	//               b      A   * x
	line.push_back({b[1], 0});
	up(i,2,n){
		dp[i] = query(a[i]);
		add(b[i], dp[i]);
	}
	cout << dp[n];
}