/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 1000005;
int n,t,a,b,c;
int sum[N];
int dp[N];
long double slope(pr l1, pr l2){return 1.0 * (l1.first - l2.first)/(l1.second - l2.second);}
bool bad(pr l1, pr l2, pr l3){ return slope(l1, l3) < slope(l1, l2); }
vector<pr> line;
#define sz line.size()
void add(pr u){
	while (sz > 1){
		if (bad(line[sz-2], line[sz-1], u)) line.pop_back();
		else break;
	}
	line.push_back(u);
}
int f(int x, pr u){return x * u.first + u.second; }
int query(int x){
	static int cur = 0;
	if (cur >= sz) cur = sz-1;
	while (cur + 1 < sz && f(x, line[cur]) < f(x, line[cur+1])) cur++;
	return f(x, line[cur]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> a >> b >> c;
		up(i,1,n) cin >> sum[i], sum[i] += sum[i-1];
		line.clear();
		line.push_back({0, 0});
		// dp[i] = a*sum[i]^2 + b*sum[i] + c - 2*a*sum[j]*sum[i] + a*sum[j]^2 - b*sum[j] + dp[j]
		//                                          A     x           B
		// get max --> A must be increasing.  
		
		for(int i=1;i<=n;++i){
			dp[i] = query(sum[i]) + a*sum[i]*sum[i] + b*sum[i] + c;
			add({-2*a*sum[i], a*sum[i]*sum[i] - b*sum[i] + dp[i]});
		}
		cout << dp[n] << '\n';
	}
}
