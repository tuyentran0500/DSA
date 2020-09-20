/*input
AOCR
ORZZ
ORZ
*/
// https://codeforces.com/problemset/problem/346/B
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 105;
string dp[N][N][N];
string a,b,virus;
int p[N];
void init(){
	// KMP
	for(int i=1;i<virus.size();++i){
		int j = p[i-1];
		while (j > 0 && virus[i] != virus[j]) j = p[j - 1];
		if (virus[i] == virus[j]) j++;
		p[i] = j;
	}
	// up(i,0,(int)virus.size() - 1) cout << p[i] << ' ';

}
string maxString(string a, string b){
	return (a.size() > b.size() ? a : b);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> virus;
	init();
	int n = a.size(), m = b.size();
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int z=0;z<virus.size();++z){
				if (dp[i][j][z].size() >= z){
					dp[i+1][j][z] = maxString(dp[i+1][j][z] , dp[i][j][z]);
					dp[i][j+1][z] = maxString(dp[i][j+1][z] , dp[i][j][z]);
					if (a[i] == b[j]){
						int cnt = z;
						while (cnt > 0 && virus[cnt] != a[i]) cnt = p[cnt - 1];
						if (virus[cnt] == a[i]) cnt++;
						if (cnt == virus.size()) continue;
						dp[i+1][j+1][cnt] = maxString(dp[i+1][j+1][cnt], dp[i][j][z] + a[i]);
					}
				}
			}
		}
	}
	string ans = "";
	up(i,0,(int)virus.size() - 1) ans = maxString(ans, dp[n][m][i]);
	cout << (ans == "" ? "0" : ans);
}