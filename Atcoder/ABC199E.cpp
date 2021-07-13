#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 18;
long long dp[1 << N];
int n,m;
vector<pr> query[N];
bool ok(int mask){
	vector<int> cnt(n, 0);
	cnt[0] = bits(mask, 0);
	for(int i=1;i<n;++i){
		cnt[i] = cnt[i-1] + bits(mask, i);
	}
	int pos = cnt[n-1] - 1;
	for(auto [y, z] : query[pos]){
		if (cnt[y] > z) return 0;
	}
	return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,m){
		int x,y,z; cin >> x >> y >> z;
		query[x-1].push_back({y-1, z});
		// at most z number from (a1...a_x) <= y;
	}
	dp[0] = 1;
	for(int mask=1;mask<(1 << n);++mask){
		if (!ok(mask)) continue;
		for(int i=0;i<n;++i){
			if (bits(mask, i)){
				int nmask = mask - (1 << i);
				dp[mask] += dp[nmask];
			}
		}
	}
	cout << dp[(1 << n) - 1];
}