# Segment Tree  
Segment Tree is a tree to help you to "querry" in segment in O(log(n)), instead of O(n).  
This blog takes inspiration from [cp-algorithm website](https://cp-algorithms.com/data_structures/segment_tree.html#counting-zero-search-kth)  

![sum-segment-tree-update](sum-segment-tree-update.png)    
## **Basic operations**  
**Init procedure:**  
We often need upto 4*N nodes to cover a n-length segment.  
```
int seg[4*N], lazy[4*N];
```
**LAZY procedure:**    
```
void lazy_upd(int u,int l,int r){
	seg[u] += lazy[u];
	if (l != r) {
		lazy[u*2] += lazy[u];
		lazy[u*2+1] += lazy[u];
	}
	lazy[u] = 0;
}
```
**UPDATE procedure:**  

```
void upd(int u,int L,int R,int l,int r,int d){
	lazy_upd(u,L,R); // Always lazy first :)))))
	if (L > R || L > r || R < l) return; 
	if (l <= L && R <= r) {
		lazy[u] = d;
		lazy_upd(u,L,R);
	}
	else {
		upd(u*2,L,MID,l,r,d);
		upd(u*2+1,MID+1,R,l,r,d);
		seg[u] = max(seg[u*2], seg[u*2 + 1]);
	}
}
```  
**Build tree**  
Suppose we have to build a tree that save the maximum value of segments from an array a[].  
```
void build(int u,int l,int r){
    if (l == r){
        seg[u] = a[l];
    }
    else{
        build(u*2,l,mid);
        build(u*2+1,mid+1,r);
        seg[u] = max(seg[u*2], seg[u*2+1]);
    }
}
```
## Persistent Segment Tree  
What if when N is really large but we never use all of the node we created ?  
All we need is to build a persistent tree.  
A persistent data structure is a data structure that remembers it previous state for each modification. This allows to access any version of this data strucuter that interest us and execute a query on it.  
Segment tree is a data strucutre that can be turned into a persistent tree data structure efficiently (both in time and memory consumption). We want to avoid copying the complete tree before each modification, and we don't want to loose $O(log{n})$ time behavior for answering range queries.  
In fact, any chcange request in the Segment Tree leads to a change in a data of only $O(log{n})$ vertices along the path starting from the root. So if we store the Segment Tree using pointers, then when performing the modification query, we simply need to create new vertices instead of changing the available vertices. Vertices that are not affected by the modification query can still be used by pointing the pointers to the old vertices. Thus for a modification query, $O(log{n})$ new vertices will be created, including a new root vertex of the Segment Tree, and the entire previous version of the tree rooted at the old root vertex will remain unchanged.  
Let's give an example implementation for the simplest Segment Tree, when there is only a query asking for sums and modification queries of single elements.  

**Finding the k-th smallest number in a range**  
> This time we have to answer queries of the form "What is the k-th smallest element in the range a[l...r]."  

First we will discuss a solution for a simpler problem: We will only consider arrays in which the element are bound by $0 \leq a[i] \leq n$. And we only want to find the k-th smallest element in some prefix of the array.  
We will use Segment Tree that counts all appearing numbers, i.e. in the Segment Tree we will store the histogram of the array.  
So the leaf vertices will be store how often the values 0 ... n-1 will be appear in the array, and other vertices store how many numbers in some range are in the array. In other words we create a regular Segment Tree with sum queries over the histogram of the array. But instead of create all n Segment Trees for every possible prefix, we will create one persistent one, that will contain the same information. We will start with an empty Segment Tree (all counts will be 0), and at the element a[0], a[1], ... a[n-1] one after each other. For each modification we will receive a new root vertex, let's call $root_i$ the root of Segment Tree after inserting the first i elements of the array. The Segment Tree rooted at $root_i$ will contains the histogram of the prefix a[0...i-1]. Using this Segment Tree, we can find in $O(log{n})$ time the position of k-th element using the same technique discusses in the counting the number of zeros, search for the k-th zero.  

Now to the queries restriction, instead of only performing these queires over a prefix of a, we want to use any arbitrary segments a[l...r]. Here we need a Segment TRee that represent the histogram of the elements in the range a[l...r]. It is easy to see that such a segment tree is just the difference between the Segment Tree rooted at $root_{r+1}$ and the segment of the $root_l$ i.e. every vertex in the [l...r] Segment TRee can be compted with the vertex of the $root_{r+1}$ tree minus the vertex of the $root_l$ tree. In the implementation of the `get_kth` function this can be handlded by passing two vertex pointer and computing the count/sum of the current segment as difference of the two counts/sums of the vertices.  
 


## Exercise:  
### 1. **[QMAX SPOJ](https://vn.spoj.com/problems/QMAX/)**  
**Problem statement:**  
> Given n elements, m updates, and q questions:  
Each update requires three numbers: (l,r,d) which means increase all the value of segment (l,r) to d.  
Each question has ask you to answer the maximum value of the segment (l,r)  
**Solution:**  
You can use LAZY update to get over the situation.  
### 2. **[KQUERY SPOJ](https://vn.spoj.com/problems/KQUERY/)**  
[Source code](./KQUERY.cpp)  

