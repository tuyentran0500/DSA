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
### 1. [IOIBIN](https://codeforces.com/group/FLVn1Sc504/contest/274710/problem/I)  
Solution: [Source code](./IOIBIN.cpp)  
### 2. [Milk scheduling](https://www.spoj.com/problems/MSCHED/)  
**Problem statements:**  
>  Farmer John has N cows that need to be milked (1 <= N <= 10,000), each of which takes only one unit of time to milk.
Being impatient animals, some cows will refuse to be milked if Farmer John waits too long to milk them. More specifically, cow i produces $g_i$ gallons of milk (1 <= $g_i$ <= 1000), but only if she is milked before a deadline at time d_i (1 <= $d_i$ <= 10,000). Time starts at t=0, so at most x total cows can be milked prior to a deadline at time t=x.
Please help Farmer John determine the maximum amount of milk that he can obtain if he milks the cows optimally.  

**Solution:**  
This is **unit-task scheduling problem**, which appears in Introduction to Algorithm.  
The solution is based on a greedy method:  
- You will optimize problem by priority the maximum profits.
- The perfect time to do "milk job" is right before the deadline.
From that you could use DSU to find the closest time to finish "milk" with cow i, right before the deadline.  
[Source code](./MSCHED.cpp)  

## DSU on tree  
**Problem statement**  
> Given a tree, every vertex has color. Query is how many vertices in subtree of vertex `v` are colored with color `c`.  
### O(nlogn) approach  
**DSU on tree template(Source: Maripium)**  
Problem: [Lomsat gelral](https://codeforces.com/contest/600/problem/E)  
```
void dfs(int u,int pre){
  cnt[u][c[u]] = 1;
  // init the map value in here.
  for(auto v : G[u]){
    if (v == pre) continue;
    dfs(v, u);
    if (cnt[u].size() < cnt[v].size()){
      cnt[u].swap(cnt[v]); // always note this.
      // do something to swap two map
    }
    // add new element to map.
    for(auto it : cnt[v]){
      cnt[u][it.first] |= it.second;
    }
  }
  ans[u] = cnt[u].size();
}
```
