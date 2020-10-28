/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int mod = 1e9 + 7;
const int M = 1000005;
void add(int& u,int v){
	u +=v;
	if (u < 0) u += mod;
	else u %= mod;
}
int a[N], cnt[M];
int ans[M];
int n;
int p2[N];
void init(){
	p2[0] = 1;
	for(int i=1;i<N;++i) p2[i] = p2[i-1] * 2 % mod;
}
void upd(int u){
	 for(int i=1;i*i<=u;++i){
	 	if (u == i * i) {
	 		cnt[i]++;
	 		break;
		}
		if (u % i == 0){
			cnt[i]++;
			cnt[u/i]++;
		}
	 }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	init();
	up(i,1,n){
		cin >> a[i];
		upd(a[i]);
	}
	int res = 0;
	for(int i=M-1;i>=2;--i){
		if (!cnt[i]) continue;
		ans[i] = 1LL * cnt[i] * p2[cnt[i]-1] % mod;
		for(int j=2*i;j<M;j+=i) add(ans[i],-ans[j]);
		add(res, 1LL * i * ans[i] % mod);
	}
	cout << res;
}