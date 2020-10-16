/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 30;
long long dp[N][2][2][2][2];
int l,r;
long long solve(int n,int lowA, int highA, int lowB, int highB){
	if (n < 0) return 1;
	long long &state = dp[n][lowA][highA][lowB][highB];
	if (state != -1) return state;
	state = 0;
	up(posA,lowA ? 0 : bits(l, n), highA ? 1 : bits(r, n)){
		up(posB, lowB ? 0 : bits(l, n), highB ? 1 : bits(r, n)){
			if (posA & posB) continue;
			state += solve(n-1, lowA | (posA != bits(l,n)), highA | (posA != bits(r, n)), 
								lowB | (posB != bits(l,n)), highB | (posB != bits(r, n)));
		}
	}
	return state;
}
int t;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> l >> r;
		memset(dp, -1LL, sizeof(dp));
		cout << solve(29,0,0,0,0) << '\n';	
	}
}