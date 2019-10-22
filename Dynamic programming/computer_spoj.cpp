#include <iostream>
using namespace std;
#define up(i,a,b) for(int (i) = (a); (i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);(i)>=(a);--(i))
#define mid ((l+r)>>1)
int x,a,y,b,n;
const int N = 1005;
pair<int,int> dp[N][N];
pair<int,int> add(pair<int,int> a, int add_val, int min_v){
	a.second += add_val;
	if (a.second >= min_v){
	 	a.first++; 
	 	a.second = 0;
	}
	return a;
}
bool f(int min_v){
	up(i,0,x) up(j,0,y) dp[i][j] = pair<int,int>(0,0);
	up(i,0,x) up(j,0,y){
		pair<int,int> cur = dp[i][j];
		if (dp[i][j].first == n) return true;
		dp[i+1][j] = max(dp[i+1][j], add(cur, a, min_v));
		dp[i][j+1] = max(dp[i][j+1], add(cur, b, min_v)); 
	}
	return false;
}
int solve(){
	int l = 0, r = (x * a + y * b)/n;
	int ans = 0;
	while (l <= r){
		if (f(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
int main(){
	cin >> x >> a >> y >> b >> n;
	cout << solve() << '\n';
	cin >> x >> a >> y >> b >> n;
	cout << solve() << '\n';
}