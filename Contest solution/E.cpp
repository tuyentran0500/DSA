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
const int N  = 200005;
int bit[N];
void upd(int u, int val){
	while (u < N) {
		bit[u] += val;
		u += (u & -u);
	}
}
int get(int u){
	int ans = 0;
	for(;u;u-=(u&-u)) ans += bit[u];
	return ans;
}
vector<int> lPos[N];
int a[N], b[N];
int f[N]; // f[i] = j: the minium length such that (i, i+j-1) contains all n pairs;
int res[N];
int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	up(i,1,n){
		cin >> a[i] >> b[i];
		lPos[a[i]].push_back(i);
		upd(a[i], 1);
	}
	for(int startPos=1;startPos<=m;++startPos){
		int l= startPos, r = m;
		if (get(r) - get(l-1) < n) {
			f[l] = m + 1;
			continue;
		}
		int ans = r;
		while (l <= r){
			if (get(mid) - get(startPos-1) == n){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		f[startPos] = ans - startPos + 1;
		// update res table
		res[ans - startPos + 1]++;
		res[m - startPos + 2]--;
		// add ending point.
		for(auto id : lPos[startPos]){
			upd(startPos, -1);
			upd(b[id], 1);
		}
	}
	int ans = 0;
	for(int i=1;i<=m;++i){
		ans += res[i];
		cout << ans << ' '; 
	}

}