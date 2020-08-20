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

## Matrix multiplication review:  
```
struct matrix{
	vector< vector<long long> > mat;
	pr matsize;
	matrix(){ matsize = {0,0}; }
	matrix(int n){
		matsize = {n, n};
		mat.assign(n, vector<long long> (n, 0LL));
		for(int i=0;i<n;++i) mat[i][i] = 1;
	}
	matrix(int n,int m){
		matsize = {n, m};
		mat.assign(n, vector<long long>(m, 0LL));
	}
	matrix(vector< vector<long long> > altMat,int n,int m){
		mat = altMat;
		matsize = {n, m};
	}
	void print(){
		for(int i=0;i<matsize.first;++i){
			for(int j=0;j<matsize.second;++j){
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
};
matrix operator*(matrix a,matrix b){
	int n = a.matsize.first, m = a.matsize.second, p = b.matsize.second;
	matrix ans = matrix(n, p);
	for(int i=0;i<n;++i){
		for(int j=0;j<p;++j){
			for(int k=0;k<m;++k) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}
matrix power(matrix a,long long n){
	matrix ans = matrix(a.matsize.first);
	for(int i=0;i<logN;++i){
		if (bits(n, i)) ans = ans * a;
		a = a * a;
	}
	return ans;
}
```  

## Gausian Elimination Technique and XOR related problem. 
**Source**: https://codeforces.com/blog/entry/68953  
The whole technique can be divided into two main parts, some problems can be solved by using only the first part.  
- 1. Represent each given number in it's binary form and consider it as a vector in $Z_{2}^{d}$ vector space, where d is the maximum possible number of bits. Then, xor of some of these numbers is equivalent to addition of the corresponding vectors in the vector space.  
- 2. Somehow, related the answer to the queries of second type with the basis of the vector found in Part 1.  
### **Part 1: Relating XOR with vector addition in $Z_{2}^{d}$**  
**Term**  
- vector space: Just a collection of vectors.  
- $Z_2:Z_m$ is the set of remainders upon division by m. So $Z_2$ is simply the set {0, 1}, since these are the only remainder possible when taken module 2.  
- $Z_{2}^{d}$ A d - dimensional vector space consisting of all the different position vectors that consists of d coordinates, all coordinates being elements of $Z_2$.  

**Problem 1: [Square Subsets](https://codeforces.com/contest/895/problem/C)**  
> Find the number of non-empty subsets, module $10^9 + 7$, of a given set of size $1 \leq n \leq 10^5$ with range of elements $1 \leq a_i \leq 70$, such that the product of its' elements is a square number.

### **Part 2: Bringing in Vector Basic**  
We need a couple of definitions now to move forward. All the vectors mentioned in what follows, exclude null vector.  
**Independent Vectors**: A set of vector $\vec{v_1}, \vec{v_2}, ...vec{v_n}$ is called independent, if none of them can be written as the sum of a linear combination of the rest.  
**Basis of a vector space**: A set of vectors is called a basic of a vector space, if all of the element vectors of that space can be written uniquely as the sum of a linear combination of elements of that basis.  
A few important properties of independent vectors and vector basis that we will need later on:  
1. For a set of independent vectors, we can change any of these vectors by adding to it linear combination of all of them, and the vectors will still stay independent. What's more facinating is that, the set of vectors in the space representable by some linear combination of this independent set stays exactly the same after the change.  
2. Notice that, in cases $Z_{2}^{d}$ vector space, the coefficient in the linear combination of vectors must lie in $Z_2$. Which means that an element vector can either stay of not stay in a combination, there is no between.  
3. THe basis is actually the smallest sized set such that all other vectors in the vector space are presentable by a linear combination of just the element vectors of that set.  
4. The basis vectors are independent.  
5. For any set with smaller number of independent vectors than the basis, not all of the vectors in the space will be representable.  
6. And there cannot possibly be larger number of independent vector than basis in set.  If d is the size of the basis of a vector space, then the moment you have d independent vectors in a set, it becomes a basis. You cannot add another vector into it, since that new vector is actually representable using the basis.  
7. For a d - dimensional vector space, it's basis can have at most d vector elements.  

With just these few properties, we can experience some awesome solutions to a few hard problems. But first, we need to see how we can efficiently find the basis of a vector space of n vectors, where each vector is an element of $Z_{2}^{d}. The algorithm works in O(n * d).  

**The algorithm**  
Suppose at each step, we're taking an input vector $\vec{v_i}$ and we already have a basis of the previously taken vectors $\vec{v_1}, \vec{v_2}...\vec{v_{i-1}}$, and now we need to update the basis such that it can also represent the new vector $\vec{v_i}$.  
In order to do that, we first need to check wheter $\vec{v_i}$ is representable using our current basis or not.  
If it is, then this basis is still enough and we don't need to do anything. But if it's not, then we just and this vector v_i to the set of basis.  
So only difficulty that remains is, to efficiently check wheter the new vector is slightly modify any new vectors before inserting it in the basis, being careful not to break down the basis:  
Let, $f(\vec{v})$ be the first position in the vector's binary representation, where the bit is set. We make sure that all the basis vectors each have a different f value.  
Here's how we do it. Initially, there are no vectors in the basis, so we're fine, there are no f values to collide with each other. Now suppose we're at the i'th step, and we're checking if vector $\vec{v_i}$ is representable by the basis or not. Since all of our basis have different f value, take the one with the least f value among them, let's call this basis vector $\vec{b_1}$.  
If $f(\vec{v_i}) < f(\vec{b_1})$ then no matter how we take the linear combination, by property 2, no linear combination of the basis vectors' can have 1 at positon $f(\vec(v_i))$. So $\vec{v_i}$ will be a new basis vector, and sinse it's f value is already different from the rest of the basis vectors, we can insert it into the set as it is and keep a record of it's f value.  
But if $f(\vec{v_i} == f(\vec{b_1})$ then we must subtract $b_1$ from $v_i$ and the move on to $\vec{b_2}$  
If, After iterating through all the basis vector $\vec{b}$ and subtracting them from $v_i$, we still find out that $\vec{v_i}$ is not a null vector, then we insert $v_i$ it into the basis and keep a record of it's f value.  
```
int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}
```  
Now, come back to the problem 1, how do you solve the answer.  
We can sum up the problem in here in a second.  
> Give n $x_1,x_2,...x_n$ numbers, and finds the number of way to choose a subset that have a xor sum equal to B.    

Consider B is a vector of d-bit, now we can reform the answer as:  
Find $a_1,a_2,a_3...a_n(0 \leq a_i \leq 1)$ such that $\sum_{i=1}^{n} a_i*x_i = B$  
We can reform it into a matrix form: `AX = B`.  
Using Gauss algorithm, we can reduce to the matrix to row echelon form, and the number of pivoted valuable is equal to the size of the basis, and the number of free variable is n - basis_size.  
We notice that the answer is `2^(n - basis_size)`.  
[Source code](./CF895C.cpp)  
Similar problem: [BADXOR](https://www.spoj.com/problems/BADXOR/)  
**Problem 2a**  
> Given a set S of size $1 \leq n \leq 10^5$ with elements $0 \leq a_i \leq 2^20$. Find the number of distinct integers that can be represented using xor over the set of given elements.  

**Solution**  
We can find the basis of the set and then because these value are linear independent, therefore, the answer must be 2^(size_of_basis).  
[Source code](./difXor.cpp)

**Problem 2b**  
> We have a graph of $2^k$ nodes numbered from 0 to $2^k - 1, 1 \leq k \leq 30$. Also we're given $1 \leq M \leq 10^5$ integers $x_1,x_2,...x_m$ within the range $0 \leq 2^k - 1$. In the graph, two vertices u and v are connected with an edge if u xor v = $x_i$ for some i. Find the number of connected components in the graph.  

We realize that u and v are belong to a connected component if u xor v = subset xor of $x_i$. Therefore the answer will be: $2^k / 2^(basisSize)$  
[Source code](./XORCMPNT.cpp)  
**Problem 3:**  
> Given a set S of size $1 \leq n \leq 10^5$ with elements $0 \leq a_i \leq 2^20$. What is the maximum possible xor of some subset of S.  

We use greedy method to choose from the basis and maximize the answer.  
Note that, it always better to choose the bigger bit because $2^i > 2^(i-1) + ... + 1$. Therefore, we will choose the basis according to their biggest bit instead of the first bit as the first two solution.  
Code:  
```
void insertVector(long long mask){
	for (int i=LOG_N-1;i>=0;--i){ // NOTE at this part.
		if (bits(mask, i) == 0) continue;
		if (!basic[i]) {
			basic[i] = mask;
			return;
		}
		else mask ^= basic[i];
	}
...
for(int i=1;i<=n;++i) insertVector(a[i]);
long long maxXor = 0;
for(int i=LOG_N-1;i>=0;--i){
	if (!basic[i]) continue;
	if (bits(maxXor, i)) continue;
	maxXor ^= basic[i];
}
```  
Similar problem:  
+ [Godzilla and Pretty XOR](https://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/S): Note that with the basis of size i, we will generate $2^i$ different subset xor. Therefore, we could use the same idea as the problem 3 and trace the answer.  
+ [Mahmoud and Ehab and yet another xor task](https://codeforces.com/contest/959/problem/F): This is quite similar with BADXOR problem in SPOJ, the problem is that we need to handle the querry offline, it works fine as DQUERY/KQUERY.  

















