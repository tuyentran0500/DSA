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
const int N = 100005;
const int logN = 35;
long long nxt[N][logN], minVal[N][logN], sum[N][logN];
int n;
long long k;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;++i){
		cin >> nxt[i][0];
	}
	for(int i=0;i<n;++i){
		cin >> minVal[i][0];
		sum[i][0] = minVal[i][0];
	}
	for(int j=1;j<logN;++j){
		for(int i=0;i<n;++i){
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
			minVal[i][j] = min(minVal[i][j-1], minVal[nxt[i][j-1]][j-1]);
			sum[i][j] = sum[i][j-1] + sum[nxt[i][j-1]][j-1];
		}
	}
	for(int i=0;i<n;++i){
		long long curPos = i, s = 0, minAns = INT_MAX;
		for(int j=logN-1;j>=0;--j) {
			if (bits(k, j)){
				s += sum[curPos][j];
				minAns = min(minAns,minVal[curPos][j]);
				curPos = nxt[curPos][j];
			}
		}
		cout << s << ' ' << minAns << '\n';
	}
}