/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 255;
const int mod = 1e9 + 7;
int pwOne[N*N], pwTwo[N*N];
int C[N][N];
int n,k;
void init(){
  pwOne[0] = pwTwo[0] = 1;
  for(int i=1;i<=n*n;++i) {
    pwOne[i] = (1LL * pwOne[i-1] * k) % mod;
    pwTwo[i] = (1LL * pwTwo[i-1] * (k-1)) % mod; 
  }
  C[0][0] = 1;
  for(int i=1;i<N;++i){
  	C[0][i] = 1;
  	for(int j=1;j<=i;++j){
  		C[j][i] = (C[j-1][i-1] + C[j][i-1]) % mod; 
  	}
  }
  // cerr << C[5][10];
}
void add(int& u,int v){
  u += v;
  if (u < 0) u += mod;
  u %= mod;
}
int multi(int u,int v){
  return (1LL * u * v) % mod; 
}
// Actually, I got really close to the real solution but didn't turn out well.  
// We will Choose the i collumns with minimize > 1, j rows with minimize > 1
// the rest will be filled randomly.
// Use inclusion-exclusion solution.  
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  init();
  int ans = 0;

  for(int i=0;i<=n;++i){
  	for(int j=0;j<=n;++j){
  		int grid = n*(i+j) - i*j;
  		int cur = multi(C[i][n], C[j][n]);
  		cur = multi(cur, pwTwo[grid]);
  		cur = multi(cur, pwOne[n*n - grid]);
  		add(ans, ((i+j) % 2 ? -cur : cur));
  	}
  }
  cout << ans;
}