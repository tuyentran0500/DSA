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
const int N = 500005;
int bit[N],n,q, c[N];
int nxtColor[N], nxtPos[N], color[N];
struct query{
	int l,r, id;
	query(){l = r = id = 0;}
	query(int _l,int _r,int _id){l = _l; r = _r; id = _id;}
};
bool operator<(query a,query b){
	return a.l < b.l;
}
query question[N];
int ans[N];
void upd(int u,int val){
	while (u <= n) {
		bit[u] += val;
		u += (u &-u);
	}
}
int get(int u){
	int ans = 0;
	while (u){
		ans += bit[u];
		u -= (u &-u);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	for(int i=1;i<=q;++i){
		cin >> question[i].l >> question[i].r;
		question[i].id = i;
	}
	for(int i=n;i>=1;--i){
		nxtPos[i] = nxtColor[c[i]];
		nxtColor[c[i]] = i;
	}
	for (int i=1;i<=n;++i) if (nxtColor[c[i]] == i) upd(i, 1);

	int curPos = 1;
	sort(question+1, question+1+q);
	for(int i=1;i<=q;++i){
		while (question[i].l != curPos){
			int nxt = nxtPos[curPos];
			upd(curPos, -1);
			if (nxt) upd(nxt, 1);
			curPos++;
		}
		ans[question[i].id] = get(question[i].r);
	}
	for(int i=1;i<=q;++i) cout << ans[i] << '\n';
}