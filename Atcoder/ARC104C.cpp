/*input
4
1 2
3 4
5 -1
-1 -1
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
#define START 1
#define END 2
const int N = 205;
bool dp[N];
int pos[N];
int state[N];
int n;
pr a[N];
bool solve(int l,int r){
	int d = (r - l + 1)/2;
	for(int i=l;i+d <= r;++i){
		int j = i+d;
		if (pos[i] && pos[j] && pos[i] != pos[j]) return false;
		if (state[i] == END) return false;
		if (state[j] == START) return false;
		if (pos[i] && a[pos[i]].second != -1 && a[pos[i]].second != j) return false;
		if (pos[j] && a[pos[j]].first != -1 && a[pos[j]].first != i) return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	bool ok = true;
	up(i,1,n){
		int l,r; cin >> l >> r;
		a[i] = {l, r};
		if (l != -1 && pos[l]) ok = false;
		if (r != -1 && pos[r]) ok = false;
		if (l >= r && r != -1) ok = false;
		if (l != -1) {
			pos[l] = i;
			state[l] = START;
		}
		if (r != -1){
			pos[r] = i;
			state[r] = END;
		}
	}
	if (!ok){
		cout << "No";
		return 0;
	}
	dp[0] = 1;
	for(int i=0;i<2*n;++i){
		if (!dp[i]) continue;
		for(int j=i+2;j<=2*n;j+=2) {
			dp[j] |= solve(i+1, j);
		}
	}
	// cout << solve(1,2) << '\n';
	// up(i,1,n) cout << dp[i*2] << ' ';
	cout << (dp[2*n] ? "Yes" : "No");
}