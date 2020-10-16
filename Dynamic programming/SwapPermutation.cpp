/*input

*/
// https://www.hackerrank.com/challenges/swappermutation/problem
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2505;
const long long mod = 1e9 + 7;
long long A[N][N], B[N][N];
long long sum[N][N];
int n,k;
long long get(int i,int l,int r){
	if (l == 0) return sum[i][r];
	return (sum[i][r] - sum[i][l-1] + mod * mod) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	// A[i][j] is the number of ways to construct the first i elements and have j inversion. 
	A[1][0] = 1;
	sum[1][0] = 1;
	up(i,1,N-1) sum[1][i] = 1;
	up(i,2,n){
		up(j,0,k){
			int l = max(j - i + 1,0), r = j;
			A[i][j] = get(i-1, l, r);
			sum[i][j] = ((j > 0 ? sum[i][j-1] : 0) + A[i][j]) % mod;
		}
	}
	// B[i][j] is the number of ways to divide the permutation of first i elements into j cycles.
	// Answer: B[i][n-k] + B[i][n-k+1].... +B[i][n];
	B[1][1] = 1;
	up(i,1,n){
		up(j,1,i){
			B[i+1][j+1] += B[i][j]; B[i+1][j+1] %= mod;
			B[i+1][j] += i * B[i][j]; B[i+1][j] %= mod;
		}
	}
	long long ans1 = 0, ans2 = 0;
	for(int i=k;i>=0;i-=2) ans1 = (ans1 + A[n][i]) % mod;
	for(int i=n-k;i<=n;++i) ans2 = (ans2 + B[n][i]) % mod;
	cout << ans1 << ' ' << ans2;
}	