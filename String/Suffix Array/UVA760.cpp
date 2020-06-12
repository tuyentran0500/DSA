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
const int N = 1005;
const int alphabet = 305;
string s,t;
int pos[N];
int p[N], c[N][2];
int pn[N];
int cnt[N];
int lcp[N];
int rmq[N][12];
int n;
void sorted_shilf(){
	memset(cnt, 0, sizeof(cnt));
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
		for(int i=n-1;i>=0;--i) p[-- cnt[c[pn[i]][(h+1) & 1]]] = pn[i];
		c[p[0]][h & 1] = 0;
		classes = 1;
		for(int i=1;i<n;++i){
			pair<int,int> cur = {c[p[i]][(h+1) & 1], c[(p[i]+ (1 << h)) % n][(h+1) & 1]};
			pair<int,int> prev = {c[p[i-1]][(h+1) & 1], c[(p[i-1] + (1 << h)) % n][(h+1) & 1]};
			if (cur != prev) classes++;
			c[p[i]][h & 1] = classes-1;
		}
	}
}
int oldN = 0;
void lcpConstruction(){
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
		lcp[pos[i]] = k;
		if (k) k--;
	}
}
void initRMQ(){
	for(int i=0;i<n;++i) rmq[i][0] = lcp[i];
	for(int h = 1; (1 << h) < n;++h){
		for(int i=0;i + (1 << h) - 1 < n; ++i){
			rmq[i][h] = min(rmq[i][h-1], rmq[i+ (1 << (h-1))][h-1]);
		}
	}
}
int get(int l,int r){
	l = pos[l];
	r = pos[r];
	if (l > r) swap(l, r);
	r--;
	int k = log2(r - l + 1);
	return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("solve.inp","r", stdin);
	// freopen("solve.out", "w", stdout);
	string c;
	int tc = 0;
	while (cin >> s){
		cin >> t;
		if (tc++) cout << '\n';
		oldN = s.size();
		s = s + "#" + t + "$";
		n = s.size();
		sorted_shilf();
		lcpConstruction();
		initRMQ();
		// for(int i=0;i<p.size();++i) cout << p[i] << '\n';
		int ans = 0;
		for(int i=0;i < oldN;++i){
			for(int j=oldN+1; j < n; ++j){ 
				ans = max(ans, get(i,j));
			}
		}
		set<string> res;
		// cout << ans << ' ' << oldN << '\n';
		for (int i=0; i < oldN; ++i){
			for(int j=oldN+1; j < n; ++j){
					if (get(i,j) == ans){
						res.insert(s.substr(i, ans));
					}
				}
		}
		if (ans == 0){
			cout << "No common sequence.\n";
		}
		else {
			for(set<string>::iterator it = res.begin(); it != res.end(); ++it) cout << *it << '\n';
		}
	}
} 