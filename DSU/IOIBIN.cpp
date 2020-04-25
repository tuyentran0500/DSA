#include <iostream>
using namespace std;
const int N = 10005; 
int n,p;
int pset[N];
// dsu
void init(){for(int i=1;i<=n;++i) pset[i] = i;}
int finds(int x){return (pset[x] == x ? x : pset[x] = finds(pset[x]));}
bool sames(int x,int y){ return (finds(x) == finds(y)); }
int unions(int x,int y){ pset[finds(x)] = finds(y); }
int main(){
	cin >> p;
	n = N - 1;
	init();
	while (p--){
		int x,y,z;	cin >> x >> y >> z;
		if (z == 1) unions(x,y);
		else cout << sames(x,y) << '\n';
	}
}