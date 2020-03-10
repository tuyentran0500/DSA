#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 1005;
int a[N], n,k;
long long POW(int n,int k){
	long long ans = 1;
	for(int i=1;i<=k;++i) ans = (ans * 1LL * n);
	return ans;
}
bool ok(int i,int j){
	int pos = 1;
	while (pow(pos,k) < 1LL* a[i] * a[j]) pos++;
	return (pow(pos,k) == 1LL * a[i] * a[j]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("D.ans","w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	long long ans = 0;
	up(i,1,n){
		up(j,i+1,n){
			if (ok(i,j)) ans++;
			//cout << i << ' ' << j << ' ' << POW(log(1LL*a[i]*a[j])/log(k), k) << '\n';
		}
	}
	cout << ans;
}