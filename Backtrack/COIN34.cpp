/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define ll long long
#define pr pair<int,int>
using namespace std;
const int N = 35;
const int INF = 2e9; 
int coins[N];
map<int,int> ans;
int t,n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	coins[0] = 2; coins[1] = 3; coins[2] = 5;
	for(int i=3;i<34;++i)
		coins[i] = coins[i-1] + coins[i-2] + coins[i-3];
	// backtrack first half.
	for(int mask=0;mask<(1 << 20);++mask){
		long long sum = 0;
		for(int j=0;j<20;++j) sum += bits(mask, j) ? coins[j] : 0;
		if (sum > INF) continue;
		ans[sum] = max(ans[sum], __builtin_popcount(mask));
	}
	// for (auto val : setSum){
	// 	cout << val << '\n';
	// }
	cin >> t;
	up(iTest,1,t){
		cin >> n;
		int res = -1;
		for (int mask=0;mask<(1 << 14);++mask){
			long long sum = 0;
			for(int j=0;j<14;++j) sum += bits(mask, j) ? coins[j+20] : 0;
			if (sum > n) continue;
			int val = ans[n - sum];
			if (val) res = max(res, ans[n - sum] + __builtin_popcount(mask));
		}
		cout << "Case #" << iTest << ": " << res << '\n';
	}

}