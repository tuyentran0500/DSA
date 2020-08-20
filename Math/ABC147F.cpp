/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
#define int long long
const int N = 200005;
long long n, x, d; 
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> d;
	if (d == 0) {
		cout << (x == 0 ? 1 : n + 1) << '\n';
		return 0;
	}
	if (d < 0) d*=-1, x*=-1;
	// assume d > 0
	map <ll, vector< pair<ll,ll> > > vecMod;
	for (ll i=0;i<=n;++i){
		ll l = i*x + 1LL*d*i*(i-1)/2;
		ll r = i*x + 1LL*d*(2*n - 1 - i)*i/2;
		// cout << l << ' ' << r << '\n';
		vecMod[(i*x) % d].emplace_back(pair<ll,ll>(l,r));
	}	
	long long ans = 0;
	for (auto node : vecMod){ 
		#define G node.second
		sort(G.begin(), G.end());
		// for (auto v : G) cout << v.first << ' ' << v.second << '\n';
		int l = 0, r = 0;
		while (l < G.size()){	
			while (r < G.size() && G[r].first <= G[l].second) {
				G[l].second = max(G[l].second, G[r].second);
				r++;
			}
			// cout << node.first << ' ' << G[l].second << ' ' << G[l].first << '\n';
			ans += (G[l].second - G[l].first + d)/d;
			l = r;
		}
	}
	cout << ans << '\n';
}