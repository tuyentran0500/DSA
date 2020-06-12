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
const int N = 2000005;
const int alphabet = 305;
char s[N],t[N];
int pos[N];
int p[N], c[N][2];
int pn[N];
int cnt[N];
int n;
void sorted_shilf(){
	// init
	for (int i=0;i<n;++i) cnt[s[i]]++;
	for (int i=1;i<alphabet;++i) cnt[i] += cnt[i-1];
	for(int i=0;i<n;++i) p[--cnt[s[i]]] = i;
	int classes = 1;
	c[p[0]][1] = 0;
	for(int i=1;i<n;++i){
		if (s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]][1] = classes-1;
	}
	// solve
	for (int h = 0; (1 << h) < n; ++h){
		for (int i=0;i<n;++i){
			pn[i] = (p[i] - (1 << h) + n) % n;
		}
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<n;++i) cnt[c[pn[i]][(h+1) & 1]]++;
		for(int i=1;i<classes;++i) cnt[i] += cnt[i-1];
		for(int i=n-1;i>=0;--i) p[--cnt[c[pn[i]][(h+1) & 1]]] = pn[i];
		c[p[0]][h & 1] = 0;
		classes = 1;
		for(int i=1;i<n;++i){
			pair<int,int> cur = pair<int,int> (c[p[i]][(h+1) & 1], c[(p[i]+ (1 << h)) % n][(h+1) & 1]);
			pair<int,int> prev = pair<int,int>(c[p[i-1]][(h+1) & 1], c[(p[i-1] + (1 << h)) % n][(h+1) & 1]);
			if (cur != prev) classes++;
			c[p[i]][h & 1] = classes-1;
		}
	}
}
int oldN = 0;
int lcpConstruction(){
	int ans = 0;
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
		while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
		if ((i < oldN && j > oldN) || (i > oldN && j < oldN))
			ans = max(ans, k);
		if (k) k--;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("solve.inp","r", stdin);
	gets(s);
	gets(t);
	oldN = n = strlen(s);
	s[n++] = '#';
	for(int i=0;t[i];++i) s[n++] = t[i];
	s[n++] = ' ';
	sorted_shilf();
	// for(int i=0;i<p.size();++i) cout << p[i] << '\n';
	int ans = lcpConstruction();
	printf("%d", ans);
} 