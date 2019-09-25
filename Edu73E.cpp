#include <bits/stdc++.h>
using namespace std;
int q;
int a,b;
string s;
void solve(){
	vector<int> list;
	int curLen = 0;
	// decode
	for(int i=0;i<s.size();++i){
		if (s[i] == '.') curLen++;
		else {
			if (curLen){
				list.push_back(curLen);
				curLen = 0;
			}
		}
	}
	int cnt_ba = 0; // b <= x <= a
	int cnt_2b = 0; // 2b <= x.
	int cnt_a = 0; // a <= x
	for (int i=0;i<list.size();++i){
		if (list[i] >= b && list[i] < a) cnt_ba++;
		if (list[i] >= 2*b) cnt_2b++;
		if (list[i] >= a) cnt_a++;
	}
	if (cnt_ba) cout << "No\n";
	else {
		if (cnt_2b >= 2) cout << "No\n";
		else cout << (cnt_a & 1 ? "Yes" : "No") << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> q;
	while (q--){
		cin >> a >> b;
		cin >> s;
		solve();
	}
}