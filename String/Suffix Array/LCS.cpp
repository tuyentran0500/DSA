/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 500005;
const int ALPHABET  = 265;
int p[N];
int lcp[N];
int pos[N];
string s,t;
int n;
void sortedShilf(string s){
	// init
	vector<int> c(n), cnt(max(ALPHABET, n) ,0);
	for(int i=0;i<n;++i) cnt[s[i]]++;
	for(int i=1;i<ALPHABET;++i) cnt[i] += cnt[i-1];
	for(int i=0;i<n;++i) p[--cnt[s[i]]] = i;
	// up(i,0,n-1) cout << p[i] << ' ';
	// cout << '\n';
	int classes = 1;
	c[p[0]] = 0;
	for(int i=1;i<n;++i){
		if (s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]] = classes - 1;
	}
	// solve
	vector<int> cn(n), pn(n);
	for(int h=0; (1 << h) < n;++h){
		for(int i=0;i<n;++i){
			pn[i] = (p[i] - (1 << h) + n) % n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for(int i=0;i<n;++i) cnt[c[pn[i]]]++;
		for(int i=1;i<classes;++i) cnt[i] += cnt[i-1];
		for(int i=n-1;i>=0;--i) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i=1;i<n;++i){
			pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
			if (cur != prev) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
}
int oldN;
int buildLCP(){
	for(int i=0;i<n;++i)
		pos[p[i]] = i;
	int k = 0;
	int ans = 0;
	for(int i=0;i<n;++i){
		if (pos[i] == n-1){
			k = 0;
			continue;
		}
		int j = p[pos[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[pos[i]] = k;
		if ((i < oldN && j > oldN) || (i > oldN && j < oldN)) ans = max(ans, k);
		if (k) k--;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	oldN = s.size();
	s = s + "#" + t + "$";
	n = s.size();
	sortedShilf(s);
	cout << buildLCP();
}