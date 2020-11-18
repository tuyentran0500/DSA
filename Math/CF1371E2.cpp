/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int a[N],n,mod;
int get(int x) { return (upper_bound(a+1,a+2+n,x) - a - 1); }
int cnt[N];
int sub(int u,int v){
	if (u >= v) return (u - v) % mod;
	return mod - (v - u) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> mod;
	up(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	a[n+1] = INT_MAX;
	// caculate i - b_i
	int id = -1;
	vector<int> ans;
	for(int x = max(0, a[n] - n); x <= a[n];++x){
		if (id == -1) id = x;
		while (id < x + n){
			cnt[sub(id,get(id))]++;
			id++;
		}
		if (!cnt[x % mod]) ans.push_back(x);
		cnt[sub(x,get(x))]--;
	}
	cout << ans.size() << '\n';
	for(auto v : ans) cout << v << ' ';
}