/*input

*/
// https://vn.spoj.com/problems/CUTSEQS/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
#define get(l,r) (s[r] - s[l-1])
using namespace std;
const int N = 100005;
const int INF = 1e18;
int seg[4*N], s[N];
int dp[N], a[N], n, m;
int leftVal[N];
void build(int u,int l,int r){
	if (l == r) seg[u] = INF;
	else {
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		seg[u] = INF;
	}
}
void upd(int u,int l,int r,int pos,int val){
	if (l > pos || r < pos || l > r) return;
	if (l == r){
		seg[u] = val;
	}
	else {
		upd(u*2,l,mid,pos,val);
		upd(u*2+1,mid+1,r,pos,val);
		seg[u] = min(seg[u*2], seg[u*2+1]);
	}
}
deque<int> dq;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		if (a[i] > m) {cout << -1; return 0; }
	}
	build(1,1,n);
	dp[1] = a[1]; 
	leftVal[1] = 1;
	for(int i=2;i<=n;++i){
		leftVal[i] = leftVal[i-1];
		while (leftVal[i] <= i && get(leftVal[i], i) > m) leftVal[i]++;
	}
	// up(i,1,n) cout << leftVal[i] << ' ';
	dq.push_back(1);
	upd(1,1,n,1,a[1]);
	for(int i=2;i<=n;++i){
		while (dq.size() && a[dq.back()] < a[i]) {
			upd(1,1,n,dq.back(), INF);
			dq.pop_back();
		}
		while (dq.size() && get(dq.front(), i) > m){
			upd(1,1,n,dq.front(), INF);
			dq.pop_front();
		}
		// update new element 
		upd(1,1,n,i,dp[dq.size() ? dq.back() : i-1] + a[i]);
		dq.push_back(i);

		upd(1,1,n, dq.front(), dp[leftVal[i]-1] + a[dq.front()]);
		dp[i] = seg[1];
	}
	// up(i,1,n) cout << dp[i] << ' ';
	cout << dp[n] << '\n';
}