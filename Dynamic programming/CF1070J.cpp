/*input

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n,m,t,sz;
// observation: We only need to split one group and all other 
// groups will stay on the same side
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> sz >> s;
		vector<int> cnt(26, 0);
		for(auto v : s) cnt[v - 'A']++;
		ll ans = 1e18;
		for(int i=0;i<26;++i){
			vector<bool> f(sz - cnt[i] + 1, 0); // subset sum
			f[0] = 1;
			for(int j=0;j<26;++j){ 
				if (j == i) continue;
				for(int k=sz-cnt[i]; k>=0;--k) if (f[k]) f[k + cnt[j]] = 1;
			}
			for(int k=0;k<=sz - cnt[i];++k){ if (!f[k]) continue;
				int st = max(0, n - k);
				int nd = max(0, m - (sz - cnt[i] - k));
				if (st + nd > cnt[i]) continue;
				ans = min(ans, 1LL * st * nd);
			}
		}
		cout << ans << '\n';
	}
}