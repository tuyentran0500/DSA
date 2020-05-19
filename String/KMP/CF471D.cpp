/*input

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int p[N];
int a[N],b[N];
int dp[N];
int n,m;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<m;++i) cin >> b[i];
	p[0] = 0;
	for(int i=1;i<=m;++i){
		int j = p[i-1];
		while (j && b[i] - b[i-1] != b[j] - b[j-1]) j = p[j-1];
		if (j && b[i] - b[i-1] == b[j] - b[j-1]) j++;
		p[i] = max(j,1);
	}
	dp[0] = 1;
	for(int i=1;i<n;++i){
		int j = dp[i-1];
		while (j && a[i] - b[j] != a[i-1] - b[j-1]) j = p[j-1];
		if (j && a[i] - b[j] == a[i-1] - b[j-1]) j++;
		dp[i] = max(1, j);
	}
	int ans = 0;
	for(int i=0;i<n;++i) {
		ans += (dp[i] == m);
	}
	cout << ans;
}