/*input

*/
// sweepline
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 400005;
int n,m;
int cnt[4*N], seg[4*N];
vector<int> zip;
struct node {
	int id, left, right, val;
	node(){id = left = right = val = 0;}
	node(int _id,int _left,int _right,int _val){id = _id; val = _val; left = _left; right = _right;}
};
bool operator<(node a, node b) {return a.id < b.id;}
vector<node> query;
void upd(int u,int l,int r,int L,int R,int t){
	if (zip[l-1] > R || zip[r-1] < L) return;
	if (L <= zip[l-1] && zip[r-1] <= R){
		cnt[u] += t;
		if (t == 1) seg[u] = zip[r] - zip[l - 1];
		else if (!cnt[u]) seg[u] = seg[u*2] + seg[u*2+1];
		// cout << zip[l-1] << ' ' << zip[r-1] << ' ' << seg[u] << '\n';
	}
	else {
		upd(u*2,l,mid,L,R,t);
		upd(u*2+1,mid+1,r,L,R,t);
		if (!cnt[u]) seg[u] = seg[u*2] + seg[u*2+1];
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2 || y1 > y2) {
			swap(x1,x2); swap(y1,y2);
		}
		zip.push_back(y1);
		zip.push_back(y1+1);
		zip.push_back(y2);
		zip.push_back(y2+1);
		query.push_back(node(x1,y1,y2,1));
		query.push_back(node(x2+1,y1,y2,-1));
	}
	sort(query.begin(), query.end());
	sort(zip.begin(),zip.end()); zip.resize(unique(zip.begin(), zip.end()) - zip.begin());
	// for(auto v : zip) cout << v << ' '; cout << '\n';
	m = zip.size() - 1;
	long long ans = 0, prev = query[0].id;
 	for(auto cur : query){
 		int l = cur.left, r = cur.right, tp = cur.val;
 		ans += (cur.id - prev) * seg[1];
 		prev = cur.id;
 		// cout << cur.id << ' ' << l << ' ' << r << ' ' << tp << '\n';
 		upd(1,1,m,l,r,tp);
 	}
 	cout << ans << '\n';
}