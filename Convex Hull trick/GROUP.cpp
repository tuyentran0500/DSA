/*input

*/
// https://vn.spoj.com/problems/GROUP/

#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 300005;
int dp[N],n;
pr point[N];
vector<pr> rec;
vector<pr> line;
// a, b
bool bad(pr l1, pr l2, pr l3){
	return (l1.first - l3.first)*(l1.second - l2.second) < (l1.first - l2.first) * (l1.second - l3.second);
}
void add(int a,int b){
	pr u = {a, b};
	while (line.size() > 1){
		#define last line.size()-1
		if (bad(line[last-1], line[last], u)) line.pop_back();
		else break;
	}
	line.push_back(u);
}
int f(int x, pr u) { return u.first * x + u.second; }
int cur = 0;
int query(int x){
	int sz = line.size();
	if (cur >= sz) cur = sz - 1;
	while (true){
		if (cur < sz - 1 && f(x, line[cur]) > f(x, line[cur+1])) cur++;
		else break;
	}
	return f(x, line[cur]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> point[i].first >> point[i].second;
	sort(point+1, point+1+n);
	reverse(point+1,point+1+n);
	rec.push_back({INT_MAX, 0});
	// make sure that we have a set of important point where x[i] >= x[j] and y[i] <= y[j].
	for(int i=1;i<=n;++i){
		if (rec.back().second < point[i].second) rec.push_back(point[i]);
	}
	// for(auto v : rec) cout << v.first << ' ' << v.second << '\n'; return 0;
	// f[i] = Y[i] * X[j] + f[j-1];
	// y    = x * a + b.  
	line.push_back({rec[1].first, 0});
	int m = rec.size();
	for(int i=1;i<m;++i){
		dp[i] = query(rec[i].second);
		if (i + 1 < m) add(rec[i+1].first, dp[i]);
	}
	cout << dp[m-1];
}