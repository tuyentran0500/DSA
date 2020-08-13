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
const int logA = 60;
const int mod = 1e9 + 7;
long long dp[logA][2][2][2];
long long l,r;
long long solve(int pos,int isLow, int isHigh,int firstBit){
	if (pos < 0) return 1;
	long long& res = dp[pos][isLow][isHigh][firstBit];
	if (res != -1) return res;
	res = 0;
	int low = (isLow ? 0 : bits(l, pos)), high = (isHigh ? 1 : bits(r, pos));
	for(int choice = low; choice <= high;++choice){
		res += 
			solve(pos - 1,isLow | (choice != low),isHigh | (choice != high), firstBit | choice == 1);
		if (choice == 1 && low == 0 && firstBit == 1)
			res += solve(pos-1, isLow, isHigh,1);
		res %= mod;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> l >> r;
	memset(dp, -1, sizeof(dp));
	cout << solve(59, 0,0,0) << '\n';
}