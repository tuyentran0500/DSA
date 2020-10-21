/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
int power(int x, int n){
	int ans = 1;
	for(int i=0;i<30;++i){
		if (bits(n, i)) ans = (1LL * ans * x) % mod;
		x = (1LL * x * x) % mod;
	}
	return ans;
}
int inv(int num, int den){
	return (1LL * num * power(den, mod - 2)) % mod;
}
int E[N], n;
void add(int &a, int b){
	a = (a + b) % mod;
}
void sub(int &a, int b){
	a = (a - b + mod) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=n;i>=2;--i){
		int x = n/i;
		E[i] = inv(x, n);
		add(E[i], inv(x, n-x));
		for(int j=2*i;j<=n;j+=i) sub(E[i], E[j]);
	}
	E[1] = inv(1, n);
	// up(i,1,n) cout << E[i] << ' ';
	int ans = 0;
	for(int i=1;i<=n;++i) add(ans, E[i]);
	// ans = inv(ans, n);n
	cout << ans;
}