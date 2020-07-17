/*input

*/
// https://www.hackerrank.com/challenges/sherlock-and-cost/problem
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int dp[N][2];
int a[N][2];
int n, t;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		up(i,1,n){
			cin >> a[i][1];
			a[i][0] = 1;
		}
		for(int i=2;i<=n;++i){
			for(int j=0;j<2;++j){
				dp[i][j] = 0;
				for(int z=0;z<2;++z){
					dp[i][j] = max(dp[i][j], dp[i-1][z] + abs(a[i][j] - a[i-1][z]));
				}
			}
		}
		cout << max(dp[n][0], dp[n][1]) << '\n';
	}
}