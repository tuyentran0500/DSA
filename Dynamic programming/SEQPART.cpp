#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 8005;
const int G = 805;
const long long INF = 1e18;
long long minCost[N][G];
long long pos[N][G];
long long s[N];
long long a[N];
int n,g;
long long cost(int l,int r){ 
	if (l > r) return INF;
	return (s[r] - s[l-1]) * 1LL * (r-l+1);
}
void solve(int l,int r, int from, int to, int seg){
	if (l > r) return;
	int mid = (l+r) >> 1;
	pos[mid][seg] = from;
	minCost[mid][seg] = minCost[from-1][seg-1] + cost(from,mid);
	up(i,from+1,to){
		if (minCost[mid][seg] >= minCost[i-1][seg-1] + cost(i, mid)){
			minCost[mid][seg] = minCost[i-1][seg-1] + cost(i, mid);
			pos[mid][seg] = i;
		}
	}
	solve(l,mid-1, from, pos[mid][seg], seg);
	solve(mid+1, r, pos[mid][seg], to, seg);
}
int main(){
	// freopen("solve.inp","r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> g;
	g = min(g, n);
	up(i,1,n) { 
		cin >> a[i]; 
		s[i] = s[i-1] + a[i]; 
	}
	up(i,1,g) minCost[0][i] = INF;
	up(i,1,n) {
		minCost[i][1] = cost(1,i);
		pos[i][1] = 1;
	}
	up(seg,2,g) solve(1,n,1,n,seg);
	cout << minCost[n][g];
}