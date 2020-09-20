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
const int N = 200005;
const int logN = 30;
int a[N], b[N];
int n;
vector<int> bitRep[logN];
long long cnt[logN];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n) cin >> b[i];

	up(i,1,n) {
		for(int j=0;j<logN;++j){
			bitRep[j].push_back(a[i] % (1 << (j+1)));
		}
	}
	up(i,0,logN-1) sort(bitRep[i].begin(), bitRep[i].end());
	// up(i,0,logN-1) {
	// 	for (auto v : bitRep[i]) cout << v << ' ';
	// 	cout << '\n';
	// }
	up(i,1,n){
		// count the number of bit 0.
		for(int j=0;j<logN;++j){
			int t = (1 << j), bitVal = b[i] % (1 << (j+1));
			cnt[j] += 
			lower_bound(bitRep[j].begin(), bitRep[j].end(), 2*t - bitVal) - lower_bound(bitRep[j].begin(), bitRep[j].end(), t - bitVal);
			cnt[j] +=  
			lower_bound(bitRep[j].begin(), bitRep[j].end(), 4*t - bitVal) - lower_bound(bitRep[j].begin(), bitRep[j].end(), 3*t - bitVal);
		}
	}
	int ans = 0;
	up(i,0,logN-1){
		// cout << cnt[i] << ' ';
		if (cnt[i] & 1) ans += (1 << i);
	}
	cout << ans;
}