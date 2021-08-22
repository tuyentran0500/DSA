/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
// https://leetcode.com/problems/gray-code/
const int N  = 16;
vector<int> grayCode(int n){
	vector<int> ans(1 << n, 0);
	if (n == 1){
		ans[1] = 1;
		return ans;
	}
	vector<int> prevAns = grayCode(n-1);
	for(int i=0;i<(1 << (n-1));++i) ans[i] = prevAns[i];
	for(int i=0;i<(1 << (n-1));++i) ans[i + (1 << (n-1))] = (1 << (n-1)) + prevAns[(1 << (n-1)) - 1 - i];
	return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> ans = grayCode(3);
	for(auto v : ans) cout << v << ' ';
}