# String Hashing  
The idea behind string hashing is using hashing to compare two substring in O(1).  
## Operations     
Pre-caculate string table.  
```
void init(ll h[] , char s[], int n){
    for (int i=1;i<=n; ++i){
        int x = (s[i] -'a');
        h[i] = (h[i-1]*26 + x ) % mod;
    }
}
```  
Get the substring's hashcode.  
```
long long get(int l,int r){
    return (h[r] - h[l] * base[r-l+1]) % mod;
}
