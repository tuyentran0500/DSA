#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 200005;
int a[N], isUnstable[N][2];
set<int> unstable;
int n,k;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,0,n-1) {
		char c; cin >> c;
		a[i] = (c == 'B');
	}
	//
	for(int i=0;i<n;++i){
		if (a[i] != a[(i-1+n) % n] && a[i] != a[(i+1) % n]){
			unstable.insert(i);
			isUnstable[i][0] = 1;
		}
	}
	if (unstable.size() == n){
		if (k & 1) up(i,0,n-1) a[i] = 1 - a[i];
		up(i,0,n-1) cout << (a[i] ? 'B' : 'W');
	}
	else{
		int cur = 0;
		while (k--){
			cur = 1 - cur;
			if (unstable.empty()) break;
			// for(set<int>::iterator it = unstable.begin(); it != unstable.end(); ++it) cout << *it << ' ';
			// cout << '\n';
			vector<int> deleteList;
			for(set<int>::iterator it = unstable.begin(); it != unstable.end(); ++it){
				int u = *it;
				a[u] = 1 - a[u];
				if ((!isUnstable[(u+1) % n][1-cur]) || (!isUnstable[(u-1+n)%n][1-cur])) {
					isUnstable[u][cur] = 0;
					deleteList.push_back(u);
				}
				else isUnstable[u][cur] = isUnstable[u][1-cur];
			}
			for(int i=0;i<deleteList.size();++i) unstable.erase(deleteList[i]);
		}
		up(i,0,n-1) cout << (a[i] ? 'B' : 'W');
	}
}