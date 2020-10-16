/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 200005;
const int logN = 18;
int p[N], n, pos[N];
int odd[N], even[N];
int mnOdd[N][logN], mnEven[N][logN];
void init(){
	int m = n/2;
	up(j,1,logN-1) up(i,1,m) mnOdd[i][j] = mnEven[i][j] = INT_MAX;
	up(i,1,m) mnOdd[i][0] = odd[i];
	up(i,1,m) mnEven[i][0] = even[i];
	up(j,1,logN-1){
		up(i,1,m) {
			if (i + (1 << j) - 1 > m) break;
			mnOdd[i][j] = min(mnOdd[i][j-1], mnOdd[i + (1 << (j-1))][j-1]);
			mnEven[i][j] = min(mnEven[i][j-1], mnEven[i + (1 << (j-1))][j-1]);
		}
	}
}
int getOdd(int l,int r){
	int k = log2(r - l + 1);
	return min(mnOdd[l][k], mnOdd[r - (1 << k) + 1][k]);
}
int getEven(int l,int r){
	int k = log2(r - l + 1);
	return min(mnEven[l][k], mnEven[r - (1 << k) + 1][k]);
}
pr solve(pr a){
	int l = a.first, r = a.second;
	int valL,valR, L, R;
	if (l & 1){
		valL = getOdd((l+1)/2, (r+1)/2); L = pos[valL];
		valR = getEven((L+1)/2, r/2); R = pos[valR];
	}
	else {
		valL = getEven(l/2, r/2); L = pos[valL];
		valR = getOdd(L/2 + 1, (r+1)/2), R = pos[valR];
	}
	return {valL, valR};
}
bool operator>(pr a, pr b){
	int u = solve(a).first, v = solve(b).first;
	return (u > v);
}
priority_queue<pr, vector<pr> , greater<pr> > pq;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n) {
		cin >> p[i];
		if (i & 1) odd[(i+1)/2] = p[i];
		else even[i/2] = p[i];
		pos[p[i]] = i;
	}
	init();
	pq.push({1, n});
	while (pq.size()){
		int l = pq.top().first, r = pq.top().second;	pq.pop();
		pr seg = solve({l,r});
		// cout << l << ' ' << r << '\n';
		int L = pos[seg.first], R = pos[seg.second];
		cout << seg.first << ' ' << seg.second << ' ';
		if (l < L-1) pq.push({l,L-1});
		if (L + 1 < R - 1) pq.push({L+1, R-1});
		if (R+1 < r) pq.push({R+1, r});
	}	

}