#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) (((x) >> (i)) & 1)
using namespace std;
const int INF = 1e9 + 7;
const int N = 20;
int cnt[N+5][N+5];
int dp[(1 << N) + 5];
string s;
int n,m;
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	cin >> s;
	up(i,0,n-2) {
		cnt[s[i]-'a'][s[i+1]-'a']++;
		cnt[s[i+1]-'a'][s[i]-'a']++;
	}
	for(int mask = 1;mask < (1 << m);++mask){
		dp[mask] = INF;
		for(int j = 0;j<m;++j) {
			if (bits(mask, j)){
				int mask_ = mask - (1 << j), cur = 0;
				for(int z = 0;z<m;++z){ 
					if (j == z) continue;
 					if (!bits(mask_, z)) cur -= cnt[j][z];
					else cur +=cnt[j][z];
				}
				cur *= __builtin_popcount(mask);
				dp[mask] = min(dp[mask], dp[mask_] + cur);  
			}
		}
	}
	cout << dp[(1 << m) - 1];
}