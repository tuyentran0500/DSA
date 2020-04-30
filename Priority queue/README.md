# Priority queue
## Basic info.  
Priority queue is a basic data structure, which handles these situations:  
- insert a node into a set, takes O(log(n))  
- take the maximum/minimum value O(log(n))  
- Delete the maximum/minimum value O(log(n))  

**Note:**
- Priority queue in C++, is define as max priority queue.  

## Problemset  
### **1. [HEAP1](https://codeforces.com/group/FLVn1Sc504/contest/274493/problem/J)**  
> Problem statement:  
Given a n-length array, your job is dividing n-length array into l smaller array, which is $a_1, a_2, a_3,...a_l$ (knows that: $\sum(a_i) = n$)  
Knowing that to divide a k-length array into two smaller array, takes k powers.  
Answer the smallest powers needed to divide the array into l arrays $a_1, a_2, a_3,...a_l$  

**Constraint:**  
- $A_i$ <= 50000.
- L <= 50000.  

**Solution:**  
This an alternative version of Huffman codes.  
[Source code](.\HEAP1.cpp)  



