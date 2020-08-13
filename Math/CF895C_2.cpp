/*input

*/
// https://codeforces.com/contest/895/problem/C
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int PRIME_NUM = 19;
const int mod =  1e9 + 7;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int n;
int a[N], maskNum[N];
// power
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}

int basis[PRIME_NUM], sz;
void insertVector(int mask){
	for(int i=0;i<PRIME_NUM;++i){
		if (!bits(mask, i)) continue;
		if (!basis[i]){
			basis[i] = mask;
			sz++;
			return;
		}
		mask ^= basis[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
		// Prepare maskNum
	for(int i=1;i<=70;++i){
		int curVal = i;
		for(int j=0;j<PRIME_NUM;++j){
			if (prime[j] > curVal) break;
			int cnt = 0;
			while (curVal % prime[j] == 0) curVal/=prime[j], cnt = !cnt;
			if (cnt) maskNum[i] += (1 << j);
		}
	}
	for(int i=1;i<=n;++i){
		cin >> a[i];
		insertVector(maskNum[a[i]]);
	}
	cout << (power(2, n - sz) + mod - 1) % mod;
}
