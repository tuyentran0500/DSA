#include <iostream>
using namespace std;
// dsu 
const int N = 2005; 
int n;
int pset[N];
// 
void init(){for(int i=1;i<=n;++i) pset[i] = i;}
int finds(int x){return (pset[x] == x ? x : pset[x] = finds(pset[x]));}
bool sames(int x,int y){ return (finds(x) == finds(y)); }
int unions(int x,int y){ pset[finds(x)] = finds(y); }
int main(){

}