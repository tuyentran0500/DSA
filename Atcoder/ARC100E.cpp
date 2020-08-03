/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 600005;
pair<int,int> b[N];
int n, a[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0;i<(1 << n);++i)	{
		cin >> a[i];
		b[i].first = a[0];
	}
	for (int m = 1; m < (1 << n); ++m){
		for (int s= m; s; s = (s-1) & m){
			if (b[m].first < a[s]) {
				b[m].second = b[m].first;
				b[m].first = a[s];
			}
			else if (b[m].second < a[s]) b[m].second = a[s];
		}
	}
	int ans = 0;
	for(int m=1;m<(1 << n);++m) {
		ans = max(ans, b[m].first + b[m].second);
		cout << ans << '\n';
	}
}