#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N  = 805;
int a[N][N];
int cnt[N][N];
int n,k;
int get(int x, int y){
	return cnt[x][y] - cnt[x-k][y] - cnt[x][y-k] + cnt[x-k][y-k];
}
bool f(int median_val){
	up(i,1,n) up(j,1,n){
		cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + (a[i][j] > median_val);
	}
	up(i,k,n) up(j,k,n){
		if (get(i,j) < k*k/2 + 1) return true;
	}
	return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) up(j,1,n) cin >> a[i][j];
	int l = 0, r = 1e9;
	int ans = 0;
	while (l <= r){
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	}

	cout << ans;
}