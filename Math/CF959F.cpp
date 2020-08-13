/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
const int logA = 20; 
int n,q;
int a[N];
pr question[N];
int ans[N];
vector< pr > query;
int basis[N], sz;
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<logA;++i){
		if (bits(n, i)) ans = ans * x % mod;
		x = (x * x) % mod;
	}
	return ans;
}
void insertVector(int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		} 
		mask^=basis[i];
	}
}
long long checkVector(int l, int mask){
	for(int i=0;i<logA;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]) return 0;
		mask^=basis[i];
	}
	return power(2, l - sz);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		query.push_back({i, -1});
	}
	for(int i=0;i<q;++i){
		int l,x; cin >> l >> x;
		question[i] = {l, x};
		query.push_back({l, i});
	}
	sort(query.begin(), query.end());
	for(int i=0;i<query.size();++i){
		int pos = query[i].first, id = query[i].second;
		if (id == -1) insertVector(a[pos]);
		else {
			ans[id] = checkVector(pos, question[id].second);
		}
	}
	for(int i=0;i<q;++i) cout << ans[i] << '\n';
}