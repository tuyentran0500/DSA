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
const int N = 100005;
const int alphabet = 505;
int p[N];
int n;
string s;
void sArray(string s){
	// init
	vector<int> c(n, 0);
	vector<int> cnt(max(n, alphabet), 0);
	for (int i=0;i<n;++i) cnt[s[i]]++;
	for (int i=1;i<alphabet;++i) cnt[i] += cnt[i-1];
	for (int i=n-1;i>=0;--i) p[--cnt[s[i]]] = i;
	int classes = 1;
	c[p[0]] = 0;
	for (int i=1;i<n;++i){
		if (s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]] = classes - 1;
	} 
	// solve
	vector<int> cn(n), pn(n);
	for (int h=0; (1 << h) < n; ++h){
		for(int i=0;i<n;++i){
			pn[i] = (p[i] - (1 << h) + n) % n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for(int i=0;i<n;++i) cnt[c[pn[i]]]++;
		for(int i=1;i<classes;++i) cnt[i] += cnt[i-1];
		for(int i=n-1;i>=0;--i) p[--cnt[c[pn[i]]]] = pn[i];
		classes = 1;
		cn[p[0]] = 0;
		for(int i=1;i<n;++i){
			pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
			if (cur != prev) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	s += '$';
	n = s.size();
	sArray(s);
	for(int i=1;i<n;++i) cout << p[i] << '\n';
}
 