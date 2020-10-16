/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1005;
int dp[N][1 << 4][1 << 4][1 << 4];
// i-3th, i-2th, i-1th, ith.  
int c[5];
int a[N];
int n,m;
void minimize(int &x,int y){
	x = min(x, y);
}
void turn_off(int& mask,int i){
	if (bits(mask,i)) mask-=(1 << i);
}
int solve(int cur,int f, int s, int t){
	int& res = dp[cur][f][s][t];
	if (cur >= n + 4) return 0;
	if (res != -1) return res;
	if (!f) return res = solve(cur+1,s, t, a[cur]);
	// take 4 * 4 square/
	res = solve(cur+4, a[cur+1], a[cur+2], a[cur+3]) + c[4];
	for(int sz = 1; sz <= 3;++sz){

		for(int i=0;i<=4-sz;++i){
			int nxt_f = f, nxt_s = s, nxt_t = t;
			for(int j=i;j<=i+sz-1;++j){
				turn_off(nxt_f, j);
				if (sz >= 2) turn_off(nxt_s, j);
				if (sz >= 3) turn_off(nxt_t, j);
			}
			minimize(res, solve(cur, nxt_f, nxt_s, nxt_t) + c[sz]);
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> c[1] >> c[2] >> c[3] >> c[4];
	up(i,1,4){
		up(j,1,n){
			char c; cin >> c;
			a[j] += (c == '*') << (i - 1);
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(4, a[1], a[2], a[3]);
}
