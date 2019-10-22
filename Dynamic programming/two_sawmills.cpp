#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 20001;
int n;
int d[N], w[N];
int sumWD[N];
int sumD[N];
int sumW[N];
int best[N];
int cost(int l,int r){
	// sigma (DR - Di) * Wi. ( L <= i <= R)
	return d[r] * (sumW[r] - sumW[l-1]) - (sumWD[r] - sumWD[l-1]); 
}
int eval(int i,int j){
	if (i > j) return 2e9 + 7;
	return cost(1,i) + cost(i+1, j) + cost(j+1, n+1);
}
void solve(int l,int r,int from,int to){
	if (l > r) return;
	int mid = (l+r) >> 1;
	best[mid] = from;
	up(i,from+1, to){
		if (eval(mid + 1, best[mid]) > eval(mid + 1, i))	best[mid] = i;
	}
	solve(l,mid-1, from, best[mid]);
	solve(mid+1,r, best[mid], to);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> w[i] >> d[i];
	up(i,1,n) {
		sumW[i] = sumW[i-1] + w[i];
		sumD[i] = sumD[i-1] + d[i];
	}
	up(i,1,n+1) d[i] = sumD[i-1];
	up(i,1,n) sumWD[i] = sumWD[i-1] + w[i] * d[i];
	sumW[n+1] = sumW[n]; 
	sumWD[n+1] = sumWD[n];
	solve(1,n,1,n);
	int ans = 2e9 + 7;
	up(i,1,n)	ans = min(ans, eval(i,best[i]));
	cout << ans;
}