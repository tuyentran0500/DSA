// https://codeforces.com/contest/729/problem/D
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N];
int n,a,b,k;
vector<int> ans;
int sum[N];
int get(int l,int r) {
	return sum[r] - sum[l-1];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> k;
	for(int i=1;i<=n;++i){
		cin >> s[i];
		sum[i] = sum[i-1] + (s[i] == '1'); 
	}
	for (int i=1;i+b-1<=n;++i){
		if (a > 1 && get(i, i+b-1) == 0){
			int j = i;
			for(j;j<i+b;++j) s[j] = '2';
			i = j - 1;
			a--; 
		}
	}
	// for(int i=1;i<=n;++i) cout << s[i];
	int cnt = 0;
	for(int i=1;i<=n;++i){
		if (s[i] == '0') cnt++;
		else cnt = 0;
		if (cnt == b){
			ans.push_back(i);
			cnt = 0;
		}
	}
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();++i) cout << ans[i] << ' ';
}