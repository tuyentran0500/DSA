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
const int N  = 105;
int n,x,a[N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	up(i,1,n){
		cin >> a[i];
		a[i] -= (i % 2 == 0);
		x -= a[i];
	}
	if (x >= 0) cout << "Yes";
	else cout << "No";
}