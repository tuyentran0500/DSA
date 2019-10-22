#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 2005;
const long long INF = 1e18;
int n,g,k;
long long minCost[N][N];
int pos[N][N];
long long a[N], sumA[N], sumA2[N];
long long getSum(int l,int r){
	return sumA[r] - sumA[l-1];
}
long long cost(int l,int r,int k){
	if (l > r) return INF;
	if (k == 1) {
		int mid = (l+r) >> 1;
		return a[mid] * (2*mid - l - r + 1) - getSum(l,mid) + getSum(mid+1,r); 
	}
	else {
		long long optVal = round(1.0 * getSum(l,r) / (r-l+1));
		// sigma a^2 - 2*a*k + k^2.
		return sumA2[r] - sumA2[l-1] - 2*getSum(l,r)*optVal + optVal*optVal*(r-l+1);
	}
}
void solve(int l,int r,int from, int to, int seg){
	if (l > r) return;
	int mid = (l+r) >> 1;
	pos[mid][seg] = from;
	minCost[mid][seg] = minCost[from-1][seg-1] + cost(from,mid,k);
	up(i,from+1,to){
		if (minCost[mid][seg] > minCost[i-1][seg-1] + cost(i, mid, k)){
			minCost[mid][seg] = minCost[i-1][seg-1] + cost(i, mid, k);
			pos[mid][seg] = i;
		}
	}
	solve(l,mid-1, from, pos[mid][seg], seg);
	solve(mid+1,r, pos[mid][seg], to, seg);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("solve.inp","r", stdin);
	cin >> n >> g >> k;
	up(i,1,n) {
		cin >> a[i];
		sumA[i] = sumA[i-1] + a[i];
		sumA2[i] = sumA2[i-1] + a[i]*a[i];
	}
	up(i,1,g) minCost[0][i] = INF;
	up(i,1,n) {
		minCost[i][1] = cost(1,i,k);
		pos[i][1] = 1;
	}	
	up(seg,2,g) solve(1,n,1,n,seg);
	cout << minCost[n][g];
}