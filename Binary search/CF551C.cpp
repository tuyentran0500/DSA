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
const int N = 100005;
int a[N];
int n, m;
bool f(ll maxTime){
	int cnt = 1;
	deque< pr > box;
	for(int i=1;i<=n;++i) if (a[i]) box.push_back({i, a[i]});
	for(int i=1;i<=m;++i){
		ll t = 0; int pos = 0;
		while (box.size()){
			int id = box.front().first, val = box.front().second; 
			ll arrivalTime = t + id - pos;
			if (arrivalTime >= maxTime) break;
			box.pop_front();
			ll nxtT = min(maxTime, arrivalTime + val);
			t = nxtT, pos = id;
			if(nxtT - arrivalTime < val) {
				int sub = nxtT - arrivalTime;
				box.push_front({pos, val - sub});
				break;
			}
		}
	}
	return box.size() == 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	ll l = 1, r = 2e14, ans = r;
	while (l <= r){
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}