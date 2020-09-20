/*input

*/
// https://codeforces.com/contest/453/problem/B
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 105;
const int PRIME = 17;
const int INF = 1e9;
int dp[N][1 << 17];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int bmask[65];
int a[N], n;
void trace(int pos,int mask){
	vector<int> ans;
	while (pos){
			for (int j=1;j<=60;++j) {
				if ((bmask[j] & mask) == bmask[j] && dp[pos][mask] == dp[pos - 1][mask ^ bmask[j]] + abs(a[pos] - j)){
					pos--;
					mask^= bmask[j];
					ans.push_back(j);
					break;
				}
			}
	}
	reverse(ans.begin(),ans.end());
	for(auto v : ans) cout << v << ' ';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,60){
		for(int j=0;j<PRIME;++j) if (i % prime[j] == 0) bmask[i] += (1 << j);
	}
	up(i,0,n) up(mask,0,(1 << PRIME) - 1) dp[i][mask] = INF;
	dp[0][0] = 0;
	up(i,1,n){
		up(mask,0,(1 << PRIME) - 1){
			for(int j=1;j<=60;++j){ 
				if ((bmask[j] & mask) == bmask[j]) 
					dp[i][mask] = min(dp[i][mask], dp[i-1][mask ^ bmask[j]] + abs(a[i] - j));
			}
		}
	}
	int mask = 0;
	up(i,1, (1 << PRIME) - 1) {
		if (dp[n][mask] > dp[n][i]) mask = i;
	}
	// cerr << dp[n][7] << ' ';
	trace(n, mask);
}