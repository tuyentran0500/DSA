#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 20005;
pair<int,int> a[N];
int n;
int pset[N];
void init(){for(int i=1;i<N;++i) pset[i] = i;}
int finds(int x){return (pset[x] == x ? x : pset[x] = finds(pset[x]));}
bool sames(int x,int y){ return (finds(x) == finds(y)); }
void unions(int x,int y){ pset[finds(y)] = finds(x); }
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	long long ans = 0;
	init();
	for(int i=1;i<=n;++i){
		if (finds(a[i].second)) {
			int k = finds(a[i].second);
			unions(k-1,k);
			unions(k, a[i].second);
			ans+= a[i].first;
		}
	}
	cout << ans;
}
/*input
7
4 70
2 60
4 50
3 40
1 30
4 20
6 10
*/ 