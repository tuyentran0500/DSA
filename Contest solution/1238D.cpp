#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 300005;
const int INF = 1e9 + 7;
string s;
int n;
int nxPos[N];
long long ans = 0;
void solve(){
	int cntBad = 0;
	nxPos[n-1] = INF;
	for(int i=n-2;i>=0;--i){
		if (s[i] == s[i+1]) nxPos[i] = nxPos[i+1];
		else nxPos[i] = i+1;
		if (nxPos[i] < n) cntBad++; 
	} 
	ans-=cntBad;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	ans = 1LL*n*(n-1)/2;
	solve();
	reverse(s.begin(), s.end());
	solve();
	for(int i=0;i<n-1;++i) if (s[i] != s[i+1]) ans++;
	cout << ans;
}