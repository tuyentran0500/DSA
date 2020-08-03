# Technique list  
## Contribution to the sum  
Blog: [Sum of expected value](https://codeforces.com/blog/entry/62690)  
- [Number of components](https://codeforces.com/contest/1151/problem/E)  
- [Intervals on Tree](https://atcoder.jp/contests/abc173/tasks/abc173_f)  

## Combinations.  
```
void init(){
	fact[0] = 1;
	up(i,1,n+k) fact[i] = (fact[i-1] * i) % mod;
}
long long power(long long x, long long n){
	long long ans = 1;
	for(int i=0;i<31;++i){
		if (bits(n, i)) ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}
long long inv(long long num, long long den){
	return (num * power(den, mod - 2)) % mod;
}
long long C(int k,int n){
	int num = fact[n];
	int den = (fact[k] * fact[n-k]) % mod;
	return inv(num, den);
}
```  
## Enumerating all submasks of a given mask  
```
for (int m = 1; m < (1 << n); ++m){
	for (int s= m; s; s = (s-1) & m){
	...
	}
}
```  
**Example problem:** [Or Plus Max](https://atcoder.jp/contests/arc100/tasks/arc100_c)  
[**Source code**](../Atcoder/ARC100E.cpp)  


