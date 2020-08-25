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
const int N = 2000005; // RE :()
const int M = 500005;
int p[N];
int nxt[M],ans[M],ok[M];
string s, t,tmp;
void KMP(){
	// bug :(
	int n = tmp.size();
	int t_size = t.size();
	int len = max(tmp.size(), t.size()) * 2;
	while (s.size() < len) s += tmp;
	s = t + "#" + s;
	len = s.size();
	for(int i=1;i<len;++i){
		int j = p[i-1];
		while (j && s[i] != s[j]) j = p[j-1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	memset(nxt, -1, sizeof(nxt));
	// create graph.
	for(int i= len - n;i<len;++i){
		if (p[i] == t_size) nxt[(i - t_size + 1) % n] = (i + 1) % n;	
	}
	int res = 0, cnt = 0;
	bool cycle = 0;
	for(int i=0;i<n;++i){
		if (!ok[i] && nxt[i] != -1){
			int j = i;
			ok[j] = ++cnt; // create new DAG component.
			ans[cnt] = 0;
			while (nxt[j] != -1){
				j = nxt[j];
				ans[cnt]++;
				if (ok[j]) { 
					if (ok[j] == cnt || ans[ok[j]] == -1) {
						ans[cnt] = -1; 
						cycle = 1;
					}
					else ans[cnt] += ans[ok[j]];
					break; 
				}
				ok[j] = cnt;
			}
			res = max(res, ans[cnt]);
		}
	}
	// for(int i=0;i<n;++i) cout << ok[i] << ' ';
	cout << (!cycle ? res : -1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tmp >> t;
	KMP();
}
