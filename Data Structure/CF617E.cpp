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
const int K = 1048600;
int a[N], n, m, k;
int xorSum[N];
struct query {
	int left, right, id;
	query(){left = right = id = 0;};
	query(int l,int r,int _id){left = l; right = r; id = _id; };
};
query q[N];
int block_size = sqrt(N);
bool compare(query a, query b){
	if (a.left / block_size != b.left / block_size) return a.left/block_size < b.left/block_size;
	return a.right < b.right;
}
int cnt[K];
long long ans[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		xorSum[i] = xorSum[i-1] ^ a[i];
	}
	for(int i=1;i<=m;++i) {
		cin >> q[i].left >> q[i].right;
		q[i].id = i;
	}
	// for(int i=1;i<=n;++i) cout << xorSum[i] << ' ';
	sort(q+1,q+1+m, compare);
	long long res = 0;
	int l = 0, r = 0; cnt[0] = 1;
	for(int i=1;i<=m;++i){
		while (r < q[i].right){
			r++;
			res += cnt[xorSum[r] ^ k];
			// cout << (xorSum[r] ^ k) << ' ' << cnt[xorSum[r] ^ k] << '\n';
			cnt[xorSum[r]]++;
		}
		while (l > q[i].left - 1){
			l--;
			res += cnt[xorSum[l] ^ k];
			cnt[xorSum[l]]++;
		}
		while (l < q[i].left - 1) {
			cnt[xorSum[l]]--;
			// cnt[xorSum[l]] = max(cnt[xorSum[l]], 0);
			res -= cnt[xorSum[l] ^ k];
			l++;
		}

		while (r > q[i].right){
			cnt[xorSum[r]]--;
			// cnt[xorSum[r]] = max(cnt[xorSum[r]], 0);
			res -= cnt[xorSum[r] ^ k];
			r--;
			// cnt[xorSum]
		}	
		ans[q[i].id] = res;
	}
	for(int i=1;i<=m;++i){
		cout << ans[i] << '\n';
	}
}
