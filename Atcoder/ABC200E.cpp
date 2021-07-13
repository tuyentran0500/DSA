#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define ll long long
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 1e6 + 5;
ll dp[3*N][4], sum[3*N][4];
int n;
ll k;
int a[4];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) {
		sum[i][1] = i;
		dp[i][1] = 1;
	}

	up(i,n+1,3*n) sum[i][1] = n;
	up(rep,2,3)
		up(i,rep,3*n) {
			if (i <= rep*n) dp[i][rep] = sum[i-1][rep-1] - sum[max(0, i - n - 1)][rep-1];
			sum[i][rep] = sum[i-1][rep] + dp[i][rep];
		}

	// up(rep,1,3){
	// 	up(i,rep,rep*n) {
	// 		cout << dp[i][rep] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	int s = 0;
	for(int pos = 3; pos <= 3*n; ++pos){
		if (sum[pos][3] >= k){
			k -= sum[pos-1][3];
			s = pos;
			break;
		}			
	}
	// cout << sum[3*n][3];
	up(i,1,n){
		int mnJ = max(1, s - i - n);
		int mxJ = min(n, s - i - 1);
		if (mxJ < mnJ) continue;
		if (k > (mxJ - mnJ + 1)) {
			k -= (mxJ - mnJ + 1);
			continue;
		}
		int j = mnJ + k - 1, z = s - i - j;
		cout << i << ' ' << j << ' ' << z << '\n';
		break;
	}
}