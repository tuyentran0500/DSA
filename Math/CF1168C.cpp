/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 300005;
const int M = 19;
int a[N];
int R[N][M], cur[M];
int n,q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	up(i,1,n) cin >> a[i];
	for(int i=0;i<M;++i) cur[i] = n+1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<M;++j) R[i][j] = n+1;
		for(int j=0;j<M;++j){
			for(int curJ = 0; curJ < M; ++curJ){
				if (bits(a[i], curJ) && cur[curJ] <= n){
					R[i][j] = min(R[i][j], R[ cur[curJ] ][j]);
				}
			}
		}
		for(int j=0;j<M;++j) 
			if (bits(a[i], j)) cur[j] = R[i][j] = i;

	}
	while (q--){
		int l,r; cin >> l >> r;
		bool ok = false;
		for(int i=0;i<M;++i) if (bits(a[r], i) && R[l][i] <= r) {
			ok = true;
			break;
		}
		cout << (ok ? "Shi" : "Fou") << '\n'; 
	}
}