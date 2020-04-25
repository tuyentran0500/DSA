#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
using namespace std;
const int N = 105;
string a[N];
int n;
char ord[5] = {'R', 'G', 'B', 'Y', 'W'};
int convert(char c){
	if (c >= '1' && c <= '5') return c - '1';
	up(i,0,4) if (ord[i] == c) return i + 5;
}
string temp[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	up(i,1,n)	cin >> a[i];
	up(i,1,n)	temp[i] = "??";
	int ans = 10;
	for(int i=0;i<(1 << 10);++i){
		// change the order. 
		for (int j=1;j<=n;++j){
			for(int k=0;k<2;++k){
				if (bits(i, convert(a[j][k]))) temp[j][k] = a[j][k];
				else temp[j][k] = '?';
			}
		}
		bool ok = true;
		up(j,1,n)	up(k,j+1,n)	
			if ((a[j] != a[k] && temp[j] == temp[k])) { 
				ok = false; 
				break; 
			}
		if (ok == true) {
			ans = min(ans, __builtin_popcount(i));
		}
	}
	cout << ans;
}