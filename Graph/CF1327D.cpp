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
int n, m;
int p[N], c[N];
bool ok[N];
int cycle_color[N];
int t;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		up(i,1,n) cin >> p[i];
		up(i,1,n) cin >> c[i];
		up(i,1,n) ok[i] = false;
		int ans = INT_MAX;
		up(u,1,n) if (!ok[u]) {
			vector<int> G;
			while (!ok[u]){
				G.push_back(u);
				ok[u] = 1;
				u = p[u];
			}
			int m = G.size();
			ans = min(ans, m);
			for(int i=0;i<min(ans, (int) sqrt(m)); ++i){
				i++;
				if (m % i == 0){
					for(int j=0;j<i;++j) cycle_color[j] = c[G[j]];
					for(int j=i;j<G.size();++j) if (cycle_color[j % i] != c[G[j]]) cycle_color[j % i] = -1;
					for(int j=0;j<i;++j) if (cycle_color[j] != -1) ans = min(ans, i); 
					i = m/i; // reverse
					for(int j=0;j<i;++j) cycle_color[j] = c[G[j]];
					for(int j=i;j<G.size();++j) if (cycle_color[j % i] != c[G[j]]) cycle_color[j % i] = -1;
					for(int j=0;j<i;++j) if (cycle_color[j] != -1) ans = min(ans, i);
					i = m/i;
				}
				i--;
			}
		}
		cout << ans << '\n';
	}
}