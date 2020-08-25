/*input

*/
// https://www.hackerrank.com/challenges/prime-xor/problem
// Unique multiset :((. Gaussimpossible :((
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int LogN = 18, LogB = 13;
const int MAX_VAL = 8192;
const int mod = 1e9 + 7;
int t,a[N],n;
int basis[N], sz;
bool isPrime[MAX_VAL];
void insertVector(int mask){
	for(int i=0;i<LogB;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		}
		mask^=basis[i];
	}
}
long long power(int n){
	long long x = 2, ans = 1;
	for(int i=0;i<LogN;++i){
		if (bits(n,i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
long long checkVector(int mask){
	for(int i=0;i<LogB;++i) {
		if (!bits(mask, i)) continue;
		if (!basis[i]) return 0;
		mask ^= basis[i];
	}
	return power(n-sz);
}
void eratosen(){
	for(int i=2;i<MAX_VAL;++i){
		if (!isPrime[i]){
			for(int j=i*i;j<MAX_VAL;j+=i){
				isPrime[j] = 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	eratosen();
	while (t--){
		cin >> n;
		memset(basis, 0, sizeof(basis));
		sz = 0;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			insertVector(a[i]);
		}
		long long ans = 0;
		for(int i=2;i<MAX_VAL;++i) if (!isPrime[i]) ans = (ans + checkVector(i)) % mod; 
		cout << ans;
	}
}