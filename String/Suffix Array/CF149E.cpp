/*input
ABCBAAB
3
BAAB
ABBA
CAA

ABCBAB
2
BAAB
ABBA
CAA

ABCBBABAA
2
BAAB
ABBA

BBAABAABBABAABA
1
BAABBBAAAAB
*/
// Clear code.
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
using namespace std;
const int N = 105005;
string s;
string p;
int m;
int n,pLen;
vector<int> Zfunction(string t){
	vector<int> ans(n, INT_MAX);
	vector<int> z(n , 0);
	int l = 0, r = 0;
	for(int i=1;i < n;++i){
		if (i <= r){
			z[i] = min(z[i-l], r - i + 1);
		}
		while (i + z[i] < n && t[z[i]] == t[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
		if (i > pLen) ans[z[i]] = min(ans[z[i]], i - pLen - 1);
	}
	return ans;
}
bool solve(string s, string p){
	if (p.size() == 1) return false;
	n = s.size() + p.size() + 1;
	pLen = p.size();
	string t = p + '#' + s;
	vector<int> pre = Zfunction(t);
	t = s + "#" + p;	reverse(t.begin(), t.end());
	vector<int> suf = Zfunction(t);
	// update pre and suf
	for(int i=0;i<=pLen;++i) 
		if (suf[i] != INT_MAX) suf[i] = s.size() - suf[i] - i;
		else suf[i] = INT_MIN;
	down(i,pLen-1,0) pre[i] = min(pre[i], pre[i+1]);
	down(i,pLen-1, 0) suf[i] = max(suf[i],suf[i+1]);
	for(int i=0;i<=pLen;++i){
		if (pre[i] == INT_MAX || suf[pLen - i] == INT_MIN) continue;
		if (pre[i] + i <= suf[pLen - i]) return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> m;
	int ans = 0;
	while (m--){
		cin >> p;
		ans += solve(s, p);
	}
	cout << ans;
}