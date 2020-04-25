# DSU
DSU(Disjoin set union) is an data structure that allows you to do two mains things:
- same(x,y): check if two elements x and y stays in the same set.
- join(x,y): join two sets contains x and y into 1 new set.
- finds(x): find the parent of the set x.  
```
void init(){for(int i=1;i<=n;++i) pset[i] = i;}
int finds(int x){return (pset[x] == x ? x : pset[x] = finds(pset[x]));}
bool sames(int x,int y){ return (finds(x) == finds(y)); }
int unions(int x,int y){ pset[finds(x)] = finds(y); }
```
## Exercise.  
1. [IOIBIN](https://codeforces.com/group/FLVn1Sc504/contest/274710/problem/I)  
Solution: [Source code](./IOIBIN.cpp)
