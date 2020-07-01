/*input
aaa
3
1
2
3

abcccad
11
1
2
3
4
5
6
7
8
9
10
11
*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 100005;
const int ALPHABET = 256;
int p[N], lcp[N];
int pos[N];
int dp[N];
int n;
string s;
void suffixArray(string s){
	vector<int> c(n), cnt(max(ALPHABET, n), 0);
	// init
	for(int i=0;i<n;++i) cnt[s[i]]++;
	for(int i=1;i<ALPHABET;++i) cnt[i] += cnt[i-1];
	for(int i=n-1;i>=0;--i) p[--cnt[s[i]]] = i;
	int classes = 1;
	c[p[0]] = 0;
	for (int i=1;i<n;++i){
		if (s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]] = classes-1;
	}
	vector <int> cn(n), pn(n);
	for (int h = 0; (1 << h) < n; ++h){
		for(int i=0;i<n;++i){
			pn[i] = (p[i] - (1 << h) + n) % n;
		} 
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for(int i=0;i<n;++i) cnt[c[pn[i]]]++;
		for(int i=1;i<classes;++i) cnt[i] += cnt[i-1];
		for(int i=n-1;i>=0;--i) p[--cnt[c[pn[i]]]] = pn[i];
		classes = 1;
		cn[p[0]] = 0;
		for (int i=1;i<n;++i){
			pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
			if (cur != prev) classes++;
			cn[p[i]] = classes-1;
		}
		c.swap(cn);
	}
}
void LCP(){
	for(int i=0;i<n;++i){
		pos[p[i]] = i;
	}
	int k = 0;
	for(int i=0;i<n;++i){
		if (pos[i] == n-1){
			k = 0;
			continue;
		}
		int j = p[pos[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[pos[i]] = k;
		if (k) k--;
	}
	for(int i=1;i<n;++i){
		dp[i] = dp[i-1] + n - 1 - p[i] - lcp[i-1];
	}
	dp[n] = dp[n-1] + 1;
	// up(i,1,n-1) cout << p[i] << ' '; cout << '\n';
	// up(i,1,n-1) cout << lcp[i] << ' '; cout << '\n';
	// up(i,1,n-1) cout << dp[i] << ' '; cout << '\n';
}
void init(){
	s += '$';
	n = s.size();
	suffixArray(s);
	LCP();
}
int t;
string findSub(int k){
	int position = lower_bound(dp+1, dp+n, k) - dp;
	string res; 
	int curPos = p[position];
	// cout << k << ' ' << position << ' ' << curPos << '\n';
	for(int i=0;i<lcp[position-1];++i) {
		res += s[curPos++];
	}
	for (int i=0;dp[position-1] + i < k;++i) res += s[curPos++];
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	init();
	while (t--){
		int k; cin >> k;
		cout << findSub(k) << '\n';
	}
};