/*input
 
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define FULL ((1 << h) - 1)
using namespace std;
const int N = 1005;
long long dp[N][1 << 4][1 << 4];
int t;
int h,w;
long long solve(int i,int pos, int f_rol, int s_rol){
	long long& res = dp[i][f_rol][s_rol];
	// cout << i << ' ' << f_rol << ' ' << s_rol << '\n';
	if (res != -1) return res;
	if (i == w + 2) return res = (s_rol == 0 && f_rol == 0);
	if (f_rol == FULL) return res = solve(i+1, 0, s_rol, 0);
	if (bits(f_rol, pos)) return res = solve(i, pos+1, f_rol, s_rol);
	res = 0;
	if (pos + 1 < h && !bits(f_rol, pos + 1)) res += solve(i, pos+2, f_rol + (3 << pos), s_rol);
	if (pos < h && !bits(s_rol, pos)) res +=solve(i, pos+1, f_rol + (1 << pos), s_rol + (1 << pos));
	// cout << i << ' ' << f_rol << ' ' << s_rol << ' '  << pos << ' ' << res << '\n';
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	h = 4;
	up(iTest,1,t){
		cin >> w;
		up(i,1,w+2) up(j,0,FULL) up(z,0,FULL) dp[i][j][z] = -1;
		cout << iTest << ' ' << solve(2, 0, 0, 0) << '\n';
	}
}