/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N  = 200005;
const int mod = 1e9 + 7;
map<int,int> cnt;
int n, a[N];
long long ans = 1;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	up(i,1,n){
		if (a[i] < i - 1){
			cout << 0;
			return 0;
		}
		ans = (1LL * ans * (a[i] - i + 1)) % mod;
	}
	cout << ans;
}