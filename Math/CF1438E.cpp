/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define pr pair<int,int>
#define ll long long

using namespace std;
const int N = 200005;
int a[N];
vector< pr > good;
int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) cin >> a[i];
	up(i,1,n){
		ll sum = 0;
		int maxBIT = 0;
		for(int j=29;j>=0;--j) if (bits(a[i], j)) {maxBIT = j; break;} 
		for(int j = i+1;j < n;++j){
			sum += a[j];
			if (sum >= (1 << (maxBIT + 1))) break;
			if (sum == (a[i] ^ a[j+1])) good.push_back({i,j+1});
		}
	}
	down(i,n,1){
		ll sum = 0;
		int maxBIT = 0;
		for(int j=29;j>=0;--j) if (bits(a[i], j)) {maxBIT = j; break;} 
		for(int j=i-1;j>1;--j){
			sum += a[j];
			if (sum >= (1 << (maxBIT + 1))) break;
			if (sum == (a[i] ^ a[j-1])) good.push_back({j-1, i});
		}
	}
	sort(good.begin(), good.end());
	good.resize(unique(good.begin(), good.end()) - good.begin());
	cout << good.size();
}