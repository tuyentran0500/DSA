// QBSTR spoj
#include <bits/stdc++.h>
using namespace std;
#define up(i,a,b) for(int (i) = (a);(i) <= (b);++(i))
#define down(i,b,a) for(int (i) = (b);(i) >= (a);--(i))
const int N = 2005;
const int M = 2005;
const int INF = 1e9 + 7;
int dp[N][N];
int nextPos[M][30];
string a,b;
int n,m;
void init(){
	n = a.size();
	m = b.size();
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j] = INF;
		}
	}
}
int cnt[30];
void solve(){
	up(i,0, 'z' -'a') cnt[i] = INF;
	for(int i = m;i>=0;--i){
		for(int j=0;j<='z'-'a';++j){
			nextPos[i][j] = cnt[j];
			if (i && (b[i-1] == (char) (j + 'a'))) cnt[j] = i;
		}
	}
	for (int i=0;i<n;++i){
		dp[i][1] = nextPos[0][a[i] - 'a'];
	}
	for(int i=0;i<n-1;++i){
		for(int k=1;k<n;++k){
			int j = dp[i][k];
			if (j == INF) continue;
			dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
			dp[i+1][k+1] = min(dp[i+1][k+1], nextPos[j][a[i+1] - 'a']);
		}
	}
	for (int i=n;i>=0;--i) if (dp[n-1][i] != INF) {
		cout << i;
		break;
	}
}
int main(){
	cin >> a >> b;
	init();
	solve();
}