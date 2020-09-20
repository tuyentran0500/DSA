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
const int N = 50005;
int a[N], b[N], n, m, k;
struct node {
	int val, idA, idB;
	node(){val = idA = idB = 0;}
	node(int _val,int _idA,int _idB) {val = _val; idA = _idA; idB = _idB; }
};
bool operator>(node a,node b){
	return a.val > b.val;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	up(i,1,n) cin >> a[i];
	up(j,1,m) cin >> b[j];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int A = 1, B = 1;
	priority_queue<node, vector<node>, greater<node> > minVal;
	minVal.push(node(a[1] + b[1], 1, 1));
	while (k--){
		int curVal = minVal.top().val, curA = minVal.top().idA, curB = minVal.top().idB;
		minVal.pop();
		cout << curVal << '\n';
		if (curA == A && A < n){
			A++;
			for(int i=1;i<=B;++i) minVal.push(node(b[i] + a[A], A, i));
		} 
		if (curB == B && B < m){
			B++;
			for(int i=1;i<=A;++i) minVal.push(node(a[i] + b[B], i, B));
		}
	}
}
