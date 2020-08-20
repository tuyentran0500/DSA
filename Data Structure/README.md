# Data structure tag  
## RMQ  
## MO algorithm
Compare function to sort the queries.  
```
S = sqrt(N);
bool cmp(Query A, Query B) // so sánh 2 truy vấn
{
  if (A.l / S != B.l / S) {
    return A.l / S < B.l / S;
  }
  return A.r < B.r;
}
```  
Implementation:  
```
while (l < inp[i].l) {add(a[l],-1); l++;}
while (r < inp[i].r) {r++; add(a[r] , 1);}
while (l > inp[i].l) {l--;add(a[l],1); }
while (r > inp[i].r) {add(a[r],-1); r--;}
// Source DQUERY
```

