# Fenwick tree  
Fenwick Tree is also called Binary Indexed Tree, or just BIT abbreviated.  
The most common application of Fenwich Tree is calculating the sum of a range.  
Fenwick was first described in a papaer titled "A new data structure for cumulative frequency tables"(Peter M.Fenwick).  
## Function:
UPDATE:  
```
void upd(int t, int u,int val){
	while(u <= n) {
		bit[t][u]+=val;
		u+=(u&-u);
	}
}
```  
GET:  
```
int get(int t,int u){
	int ans = 0;
	while(u){
		ans += bit[t][u];
		u-=(u&-u);
	}
	return ans;
}
```  
Explain: x - (x&-x) = extract the last set bit in the binary representation of i.  
Make an unique vector:
```
sort(a.begin(), a.end());
a.resize(unique(a.begin(), a.end()) - a.begin());
```
