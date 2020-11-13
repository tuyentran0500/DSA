/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2LL)
#define pr pair<int,int>
using namespace std;
const int N = 755;
int a[N],n,t; 
long long dp[N];
long long q;
bool f(long long val,int k){
	priority_queue<int, vector<int>, greater<int>> pq;
	long long sum = val;
	// cout << val << ' ' << k << '\n';
	for(int i=1;i<=n;++i){
		if (sum + a[i] >= 0) {
			pq.push(a[i]);
			sum += a[i];
		}
		else {
			#define u pq.top()
			if (pq.size() && u < a[i]) {
				sum += a[i] - u;
				pq.pop();
				pq.push(a[i]);
			}
		}
	}
	return pq.size() >= k;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	up(i,1,n) cin >> a[i];
	dp[0] = 0;
	up(k,1,n){
		long long l = 0, r = 1e15, ans = 0;
		while (l <= r){
			if (f(mid, k)){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		dp[k] = ans;
	}
	dp[n+1] = 2e15; // increase the limit :((
	// up(i,0,n) cout << dp[i] << ' ';
	while(t--){
		cin >> q;
		int ans = upper_bound(dp, dp+1+n, q) - dp - 1;
		cout << n - ans << '\n';
	}
}