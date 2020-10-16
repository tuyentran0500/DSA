/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 2005;
string s, t;
int n;
int cnt[30];
vector<int> ans;
void solve(int pos,string &s){
	//t_(pos+1), t_(pos+2), ... t_(n-1).... t_posB
	int minPos = n - 1 - pos;
	string A, B;
	for(int i=minPos;i<n;++i){
		if (s[i] == t[pos]){
			A = s.substr(0, i);
			B = s.substr(i+1,n - i + 1);
			break;
		}
	} 
	// AzB --> B'zA'
	ans.push_back(n);
	// B'zA' --> AB'z
	ans.push_back(A.size());
	// AB'z --> zAB'
	ans.push_back(1);
	reverse(B.begin(), B.end());
	s = t[pos] + A + B;
	// cout << s << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> s >> t;
	for(int i=0;i<s.size();++i) cnt[s[i] - 'a']++;
	for(int i=0;i<t.size();++i) cnt[t[i] - 'a']--;
	for(int i=0;i<='z'-'a';++i) if (cnt[i]) {
		cout << -1;
		return 0;
	}
	for(int i=n-1; i>=0; --i){
		solve(i, s);
	}
	cout << ans.size() << '\n';
	for(auto v : ans) cout << v << ' ';
}