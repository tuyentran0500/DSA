/*input

*/
// https://codeforces.com/contest/633/problem/D
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1005;
map<int,int> cnt;
int ans;
int a[N], n;
void solve(int i,int j){
	cnt[a[i]]--;
	cnt[a[j]]--;
	vector<int> f;
	int fibSiz = 2;
	f.push_back(a[i]);
	f.push_back(a[j]);
	while (cnt[f[fibSiz-1] + f[fibSiz-2]] > 0){
		f.push_back(f[fibSiz-1] + f[fibSiz-2]);
		cnt[f.back()]--;
		fibSiz++;
	}
	// revert
	for(int i=0;i<fibSiz;++i) cnt[f[i]]++;
	// for(int i=0;i<fibSiz;++i) cout << f[i] << ' '; 
	ans = max(ans, fibSiz);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i], cnt[a[i]]++;
	if (cnt[0] >= 2) ans = cnt[0];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;j++)	if (i != j && (a[i] != a[j] || a[i])) solve(i,j);
	}
	cout << ans << '\n';
}
