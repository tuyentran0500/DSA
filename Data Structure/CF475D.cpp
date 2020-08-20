/*input

*/
#include <map>
#include <iostream>
#include <algorithm>
#define pr pair<int,int>
using namespace std;
const int N = 100005;
int a[N];
map<int, long long> result;
int n,q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i)	cin >> a[i];
	map<int,int> curGCD, preGCD;
	for(int i=1;i<=n;++i){
		curGCD.clear();
		for(auto preVal : preGCD){
			curGCD[__gcd(a[i], preVal.first)] += preVal.second; 
		}
		curGCD[a[i]]++;
		for(auto val : curGCD){
			result[val.first] += val.second;
		}
		swap(preGCD, curGCD);
	} 
	cin >> q;
	while (q--){
		int x; cin >> x;
		cout << result[x] << '\n';
	}
}