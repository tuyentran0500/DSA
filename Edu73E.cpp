#include <bits/stdc++.h>
using namespace std;
int q;
int a,b;
string s;
bool isDanger(int x){
	if (x < b) return false;
	if (x >= b && x < a) return true;
	if (x >= 2*b) return true;
	return false;
}
bool isSafe(int x){
	return (x >= a && x < 2*b);
}
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
	if (curLen) list.push_back(curLen);
	int cnt_ba = 0; // b <= x <= a
	int cnt_a2b = 0; // 2b <= x.
	int cnt_2b = 0;
	int val = 0;
	for (int i=0;i<list.size();++i){
		if (list[i] < b) continue;
		if (list[i] >= b && list[i] < a) cnt_ba++;
		else if (list[i] < 2*b) cnt_a2b++;
			else {
				cnt_2b++; 
				val = list[i];
			}
	}
	if (cnt_ba) cout << "No\n";
	else {
		if (cnt_2b >= 2) cout << "No\n";
		else {
			if (val){
				bool ok = false;
				for(int i=0;i+a <= val;++i){
					if (isDanger(i) || isDanger(val-i-a)) continue;
					if ((cnt_a2b + isSafe(i) + isSafe(val-i-a)) % 2 == 0) ok = true;
				}
				if (ok == true) cout << "Yes\n";
				else cout << "No\n";
			}
			else cout << (cnt_a2b % 2 ? "Yes" : "No") << '\n';
		}
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