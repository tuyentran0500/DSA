/*input

*/
// https://codeforces.com/contest/1165/problem/F1
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 400005;
int a[N];
int n,m;
int d[N], t[N];
 
bool check(int num_days){
	vector<int> lastD(n+1, -1);
	vector<int> sales(num_days+1, 0);
	for(int i=1;i<=m;++i){
		if (d[i] <= num_days) lastD[t[i]] = max(lastD[t[i]], d[i]);
	}
	int late_offer = 0;
	for(int i=1;i<=n;++i) {
		if (lastD[i] != -1){
			sales[lastD[i]]+=a[i];
		}
		else late_offer += a[i];
	}
	int money = 0;
	for(int i=1;i<=num_days;++i){
		money++;
		int sale_buy = min(money, sales[i]);
		money -= sale_buy;
		late_offer += sales[i] - sale_buy;
	}
	// cout << num_days << ' ' << money << ' ' << late_offer << '\n';
	return (money >= late_offer * 2);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n) cin >> a[i];
	up(i,1,m){
		cin >> d[i] >> t[i];
	}
	int l = 1, r = 400000;
	int ans = 0;
	// cout << check(8) << '\n';
	while (l <= r){
		if (check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}