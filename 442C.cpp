#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 5 * 10e5 + 5;
int a[N];
int n;
int cnt;
long long ans;
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	while(n--){
		cin >> a[cnt];
		while (cnt >= 2 && a[cnt-1] <= a[cnt] && a[cnt-1] <= a[cnt-2]){
			ans += min(a[cnt], a[cnt-2]);
			cnt--;
			a[cnt] = a[cnt+1];
		}
		cnt++;
	}
	sort(a,a+cnt);
	// for(int i=0;i<cnt;++i)	cout << a[i] << ' ';	cout << '\n';
	for(int i=0;i<cnt-2;++i){
		ans += a[i];
	}	
	cout << ans;
}