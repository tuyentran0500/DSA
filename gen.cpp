#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 300005;
const int INF = 1e9 + 7;
int main(){
	int q = rand() % 100 + 1;
	cout << q << '\n';
	while (q--){
		int n = rand() % 20 + 1;
		cout << n << '\n';
		for(int i=1;i<=n;++i)	cout << rand % n + 1 << ' ';
		cout << '\n';
	}
}