/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N = 1000005;
const int M = 3e5 + 5; // WHY ???????
int d[N], a[M];
int t,n,m;
// template for BIT
ll bit[M];
void upd(int u,int val){
	while (u <= n) {
		bit[u] += val;
		u += (u &-u);
	}
}
ll get(int u){
	ll ans = 0;
	while (u){
		ans += bit[u];
		u -= (u &-u);
	}
	return ans;
}
void init(){
	for(int i=1;i*i < N;++i){
		d[i*i]++;
		for(int j=i*(i+1); j < N; j+=i) d[j]+= 2;
	}
	// up(i,1,10) cout << d[i] << ' ';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	t = 1;
	while (t--){
		cin >> n >> m;
		set<int> possible;
		up(i,1,n) {
			cin >> a[i];
			if (a[i] > 2) possible.insert(i);
			upd(i, a[i]);
		}
		while (m--){
			int t,l,r; cin >> t >> l >> r;
			if (t == 1){
				vector<int> dList;
				for(auto it = possible.lower_bound(l);it != possible.end() && *it <= r;++it){
					int pos = *it;
					upd(pos, d[a[pos]] - a[pos]);
					a[pos] = d[a[pos]];
					if (a[pos] <= 2) dList.push_back(pos);
				}
				for(auto v : dList) possible.erase(v);
			}
			else {
				cout << get(r) - get(l-1) << '\n';
			}
		}
	}
}