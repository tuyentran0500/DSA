/*input

*/
// Floyd
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 15;
#define knight 0 
#define bishop 1
#define rook 2
#define cPos(x,y) (x - 1) * n + (y-1)
const pr INF = {1e9, 1e9};
pr d[N*N][3][N*N][3];
pr dp[N*N][3];
int a[N][N];
int pos[N*N],n;
int ox[] = {-2,-2,2,2,1,1,-1,-1};
int oy[] = {1,-1,1,-1,2,-2,2,-2};
pr operator+(pr a, pr b){
	return {a.first + b.first, a.second + b.second};
}
bool ok(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		up(j,1,n) {
			cin >> a[i][j];
			pos[a[i][j]] = cPos(i,j);
		} 
	}
	up(s,0,n*n-1) up(t,0,n*n-1) up(moveS,0,2) up(moveT,0,2) d[s][moveS][t][moveT] = INF;
	up(s,0,n*n-1) up(moveS,0,2) up(moveT,0,2) d[s][moveS][s][moveT] = {moveS !=  moveT, moveS != moveT}; 
	// knight is the last move.
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int e = 0; e < 8; ++e){
				int ni = i + ox[e], nj = j + oy[e];
				if (!ok(ni,nj)) continue;
				int posS = cPos(i,j), posT = cPos(ni, nj);
				d[posT][knight][posS][knight] = {1, 0};
			}
		}
	}
	// rook is the last move.
	up(i,1,n){
		up(j,1,n){
			up(z,1,n){
				if (z == i) continue;
				int posS = cPos(i,j), posT = cPos(z, j);
				d[posT][rook][posS][rook] = {1, 0};
			}
			up(z,1,n){
				if (z == j) continue;
				int posS = cPos(i,j), posT = cPos(i, z);
				d[posT][rook][posS][rook] = {1, 0};
			}
		}
	}
	// bishop is the last move.
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int z=-n;z<=n;++z){
				int ni = i + z, nj = j + z;
				if (!ok(ni, nj) || z == 0) continue;
				int posS = cPos(i,j), posT = cPos(ni, nj);
				d[posT][bishop][posS][bishop] = {1, 0};
			}
			for(int z=-n;z<=n;++z){
				int ni = i + z, nj = j - z;
				if (!ok(ni, nj) || z == 0) continue;
				int posS = cPos(i,j), posT = cPos(ni, nj);
				d[posT][bishop][posS][bishop] = {1, 0};
			}
		}
	}
	up(k,0,n*n-1){
		up(moveK,0,2){
			up(s,0,n*n-1){
				up(moveS,0,2){
					up(t,0,n*n-1){
						up(moveT,0,2){
							d[s][moveS][t][moveT] = min(d[s][moveS][t][moveT], d[s][moveS][k][moveK] + d[k][moveK][t][moveT]);
						}
					}
				}
			}
		}
	}
	for(int i=2;i<=n*n;++i){
		for(int moveT=0;moveT<3;++moveT){
			dp[pos[i]][moveT] = INF;
			for(int moveS = 0;moveS < 3; ++moveS){
					int s = pos[i-1], t = pos[i];
					dp[t][moveT] = min(dp[t][moveT], dp[s][moveS] + d[s][moveS][t][moveT]);
			}
		}
	}
	pr ans = INF;
	up(moveT,0,2) ans = min(ans, dp[pos[n*n]][moveT]);
	cout << ans.first << ' ' << ans.second << '\n';
}