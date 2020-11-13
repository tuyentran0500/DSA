/*input

*/
// https://codeforces.com/group/FLVn1Sc504/contest/274493/problem/E
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define int long long
#define mid ((l+r)/2)
#define pr pair<int,int>

using namespace std;
const int N = 100005;
int s[N], v[N];
vector<pr> G[N];
int d[N], dp[N];
int sz;

pr line[N];
struct history{
	int pos, len;
	pr val;
	history(int _pos,pr _val,int _len){pos = _pos; val = _val; len = _len;}
};
vector<history> activities;

long double slope(pr l1, pr l2){
	return 1.0*(l1.second - l2.second)/(l1.first - l2.first);
}
bool bad(pr l1, pr l2, pr l3){
	return slope(l1, l3) > slope(l1,l2);
}

int n;
int f(int x,pr u){return u.first * x + u.second; }
// convex hull
int query(int x){
	if (!sz) return 0;
	int ans = f(x, line[0]);
	// for(auto node : line) cout << f(x, node) << ' '; cout << '\n';
	int l = 1, r = sz - 1;
	while (l <= r){
		int val1 = f(x, line[mid-1]), val2 = f(x, line[mid]);
		if (val1 > val2){ // really ??
			l = mid + 1;
		}
		else r = mid - 1;
		ans = min(ans, min(val1, val2));
	}
	return ans;
}
void add(pr u){
	int l = 1, r = sz - 1, k = sz;
	while (l <= r){
		if (bad(line[mid-1], line[mid], u)){
			k = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	activities.push_back(history(k, line[k], sz));
	sz = k + 1;
	line[k] = u;
}
void rollback(){
	history node = activities.back(); activities.pop_back();
	sz = node.len; line[node.pos] = node.val;
}
void dfs(int u,int pre){
	// dp[i] = s[i] + v[i] * d[i] + dp[j] - v[i] * d[j];
	//                                b      x     A
	dp[u] = query(v[u]) + s[u] + v[u] * d[u];
	vector<pr> storage;
	pr nLine = {-d[u], dp[u]};
	// add
	add(nLine);
	for(auto node : G[u]){ int v = node.first, c = node.second;
		if (v == pre) continue;
		d[v]  = d[u] + c;
		dfs(v, u);
	}
	rollback();
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,2,n){
		int u,v,c; cin >> u >> v >> c;
		G[u].push_back({v,c});
		G[v].push_back({u,c});
	}
	up(i,2,n) cin >> s[i] >> v[i];
	dfs(1, 0);
	up(i,2,n) cout << dp[i] << ' ';
}	