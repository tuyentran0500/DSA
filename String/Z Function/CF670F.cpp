/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1000001;
string s,sub;
int cnt[30];
int p[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> sub;
	for(auto c : s) cnt[c - '0']++;
	for(auto c : sub) cnt[c - '0']--;
	int num_digit = 0;
	for(int i=1;i<N;++i){
		string digit = to_string(i);
		bool ok = true;
		for(auto c : digit) if (--cnt[c - '0'] < 0) ok = false;
		for(auto c : digit) cnt[c - '0']++;
		if (ok && i == s.size() - digit.size()) {
			num_digit = i;
			break;
		}
	}
	s = to_string(num_digit);
	for(auto c : s) --cnt[c - '0'];
	s = "";
	for (int i=1;i<=9;++i) if (cnt[i]) {
		s += (i + '0');
		cnt[i]--;
		break;
	}
	for(int i=0;i<=9;++i) {
		while (cnt[i]--) s += (i + '0');
	}
	if (s.size() == 0) {
		cout << sub;
		return 0;
	}
	string ans = "A";
	// first string
	if (sub[0] != '0') {
		ans = sub;
		for(int i=0;i<=9;++i) cnt[i] = 0;
		for(auto c : s) cnt[c - '0']++;
		for(int i=0;i<=9;++i) {
			while (cnt[i]--) ans += (i + '0');
		}
	}
	if (s[0] != '0'){
		// second string
		string cur = ""; cur+=s[0];
		for(int i=1;i<s.size(); ++i){
			if (s[i] < sub[0]) {
				cur += s[i];
			}
			else {
				cur += sub;
				while (i < s.size()) cur += s[i++];
			}
		}
		if (cur.size() < num_digit) cur += sub;
		// cout << cur << '\n';
		ans = min(ans, cur);
		// final string
		cur = ""; cur += s[0];
		for(int i=1;i<s.size(); ++i){
			if (s[i] <= sub[0]) {
				cur += s[i];
			}
			else {
				cur += sub;
				while (i < s.size()) cur += s[i++];
			}
		}
		if (cur.size() < num_digit) cur += sub;
		// cout << cur << '\n';
		ans = min(ans, cur);
	}
	cout << ans;
}