/*input

*/
// https://codeforces.com/contest/1183/problem/F
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], n;
int t;
bool check(int n, vector<int> ans){
	for(int i=0;i<ans.size();++i) if (ans[i] % n == 0) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		set<int> s;
		vector<int> ans;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			s.insert(a[i]);
		}
		sort(a+1,a+1+n);
		int res = 0;
		for(int i=n;i>=1;--i){
			if (ans.size() == 3) break;
			if (check(a[i], ans)) continue;
			if (a[i] % 30 == 0){
				if (s.find(a[i]/3) != s.end() && s.find(a[i]/2) != s.end() && s.find(a[i]/5) != s.end()) 
					res = max(res, a[i]/2 + a[i]/3 + a[i]/5); 
			}
			ans.push_back(a[i]);
		}
		int curSum = 0;
		for(int i=0;i<ans.size();++i) curSum += ans[i];
		res = max(res, curSum);
		cout << res << '\n';
	}
}	