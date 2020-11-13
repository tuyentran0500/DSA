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
const int N = 200005;
int bit[N], n;
int a[N];
void upd(int u,int val){
	while (u) {
		bit[u] += val;
		u -= (u &-u);
	}
}
int get(int u){
	int ans = 0;
	while (u <= n){
		ans += bit[u];
		u += (u &-u);
	}
	return ans;
}
vector< pr > q;
set<int> mx, mn;
ll add(int x){
	static ll res = 0;
	static int med = 0;
	if (x < med){
		mn.insert(x); res -= x;
	} 
	else {
		mx.insert(x); res += x;
	}
	if (mx.size() > mn.size()){
		auto minVal = *mx.begin();
		res -= 2*minVal;
		mx.erase(minVal);
		mn.insert(minVal);
	}
	if (mn.size() > mx.size() + 1){
		auto maxVal = *(--mn.end());
		res += 2*maxVal;
		mn.erase(maxVal);
		mx.insert(maxVal);
	}
	med = *(--mn.end());
	return res + (mn.size() > mx.size() ? med : 0);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		q.push_back({a[i], i});
	}
	sort(q.begin(), q.end());
	ll ans = 0;
	int l = n+1, r = 0;
	for(auto node : q){ 
		int val = node.first, id = node.second;
		ans += get(id);
		upd(id, 1);	
		cout << ans + add(id) - 1LL*val*val/4 << '\n';
	}
}
