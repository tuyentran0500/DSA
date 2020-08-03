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
const int MAX_N = 1e6 + 5;
const int MAX_ARR = 3000005;
long long dp[3][MAX_ARR], pref[3][MAX_ARR];
long long get(int id,int l,int r){
	return (l <= 0 ? pref[id][r] : pref[id][r] - pref[id][l-1]);
}
vector<int> findCell(int N, long long index){
	// find sum 
	#define n N
	index++;
	for (int i=0;i<n;++i){
		dp[0][i] = 1;

	}
	for (int i=0;i<=3*n-3;++i){
		if (i < n) pref[0][i] = i+1;
		else pref[0][i] = pref[0][i-1];
	}
	for (int i=1;i<3;++i){
		for (int sum = 0;sum <= 3*n - 3;++sum){
			dp[i][sum] = get(i-1, sum - n + 1, sum);
			pref[i][sum] = (sum ? pref[i][sum-1] : 0) + dp[i][sum];
		}
	}
	long id = 2, s = 0;
	for (s = 0; s <= 3*n - 3; ++s) 
		if (pref[id][s] >= index) {
			index -= (!s ? 0 : pref[id--][s-1]);
			break;
		}
	vector<int> ans;
	while (id >= 0){
		int curSum = 0;
		for (int i=s;i>=0;--i){
			if (curSum + dp[id][i] >= index){
				index -= curSum;
				ans.push_back(s - i);
				s = i;
				id--;
				break;
			}
			else curSum += dp[id][i];
		}
	}
	ans.push_back(s);
	return ans;
}
int n;
long long index;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> index;
	vector<int> ans = findCell(n, index);
	for (int i=0;i<ans.size();++i) cout << ans[i] << ' ';
}