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
int altRow[N], altCol[N];
pr qCell[N];
int a[N][N];
int n;
set<int> freeRow;
set<int> freeCol;
int cntRow[N], cntCol[N];
struct answer{
	int t,i,j;
	answer(){t = i = j = 0;};
	answer(int _t,int _i,int _j) {t = _t; i = _i; j = _j;}
};
vector<answer> ans;
void solve(int curN,int k){
	if (n == 0 || k == 0) return;
	int firstFreeCol = *freeCol.begin();
	if (curN!= firstFreeCol){
		ans.push_back(answer(2, firstFreeCol, curN));
		swap(altCol[firstFreeCol], altCol[curN]);
	}
	freeCol.erase(firstFreeCol);
	// check if exist
	for(int i=1;i<=curN;++i){
		if (cntRow[altRow[i]]){
			if (i != curN) ans.push_back(answer(1, i, curN));
			for(int j=1;j<=curN;++j){
				if (a[altRow[i]][altCol[j]]) {
					if (--cntCol[altCol[j]] == 0)	freeCol.insert(j);
					k--;
				}
			}
			swap(altRow[i], altRow[curN]);
			solve(curN-1, k);
			return;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) freeCol.insert(i);

	for(int i=1;i<n;++i){
		// .second is col
		// .first is row
		cin >> qCell[i].first >> qCell[i].second;
		a[qCell[i].first][qCell[i].second] = 1;
		if (freeCol.find(qCell[i].second) != freeCol.end()) freeCol.erase(qCell[i].second);
		cntRow[qCell[i].first]++;
		cntCol[qCell[i].second]++;
	}	
	for(int i=1;i<=n;++i) altRow[i] = altCol[i] = i;
	// for(auto freeCol )
	solve(n,n-1);
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();++i) cout << ans[i].t << ' ' << ans[i].i << ' ' << ans[i].j << '\n';
}