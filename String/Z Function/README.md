# Z Function and its calculation.  
Suppose we are given a string s of length n. The **Z-function** for this string is an array of length n where the i-th element is equal to the greatest number starting from the position i that coincide with the firsts characters of s.  
In other word, z[i] is the length of the longest common prefix between s and the suffix of s starting at i.  
**Note:** In this article, to avoid ambiguity, we assume 0-based indexes.  
Define: z[0] = 0.  
This article presents an algorithm for calculating the Z-function in O(n) time, as well as various of its applications.  
## **Example**  
For example, here are the values of the Z-function computed for different strings.  
+ "aaabaab" - [0,2,1,0,2,1,0]    
+ "abacaba" - [0,0,1,0,3,0,1]  
## Trival algorithim.  
We could have an O(n^2) running time algorithm.  
```
vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}
```  
## **Efficient algorithm to compute then Z-function**  
To obtain an efficient algorithm we will compute the values of z[i] in turn from 1 to n-1, but at the same time, when computing a new value, we'll try to make the best use possible of previously computed values.  
For the sake of brevity, let's call **segment matches** those substrings that coincide with a prefix of s. For examplem the value of the desired Z-function z[i] is the length of the segment match starting at position i (and that ends at position i + z[i] - 1).  
To do this, we will keep **the [l,r] indices of the rightmost segment match**.  That is, among all detected segments we will keep the one that ends rightmost. In a way, the index r can be seen as the "boudary" to which our string s has been scanned by the algorithm, everything beyond that point is not yet known.  
Then, if the current index(for which we have to compute the next value of the Z-function) is i, we have one of two options:  
+ i > r - the current position is **outside** of what we have already processed.  
We will then compute z[i] with the **trivial algorithm**. Note that in the end, if z[i] > 0, then we have to update the r = i + z[i] - 1.  
+ i <= r - the current position is inside the current segment match [l,r].  
Then we can use the already calculated Z-values to "initialize" the value of z[i] to something (it sure is better than "staring from zero"), maybe even some big numbers.  
For this, we observe that the substrings s[l..r] and s[0...r-l] **match**. This means that as an initial approximation for z[i], we can take the value already computed for the corresponding segment s[0..r-l] and that is z[i-l].  
However, there value z[i-l] could be too large, when applied to position i, it could be exceed the index r. This is not allowed because we know nothing about the characters to the right of r, they may different from those required.  
Thus, as an **initial approximation** for z[i], we can safely take:

$$z_0[i] = min(r-i+1, z[i-l])$$

After having z[i] initialized to $z_0[i]$, we try to increment z[i] by running the **trivial algorithm**, because in general, after border r, we cannot know if the segment will continue to match or not.  
## **Implementation**.  
By splitting into two cases, we could have one simple algorithm.  
```
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
```  
By using the concept of two pointers technique, we could understand that the running time of the algorithm is O(n).  
## **Application**.  
We will now consider some uses of Z-functions for specific tasks.  
These application will be largely similar to applications of **prefix function**.  
### **Search the substring**  
> To avoid confusion, we call t the **string of text**, and p the **pattern**. The problem is: find all occurrences of the pattern p inside the text t.  

Similar to KMP sections, we have a new string s = p + "#" + t.
And your mission will be running Z-function to the whole string s, find where z[i] = p.size().  
[**Source code**](./SUBSTR.cpp)  
### **Number of distinct substrings in a string**  
> Given a string of length n, count the number of distinct substrings of s.  

We'll solve this problem iteratively. That is, knowing the current number of different substrings, recalculating this amount after adding to the end of s one characters.  
So let k be be the current number of distinct substrings of s. We append a new character c to s. Obviously, there can be some new subsstrings ending in the new character c(namely, all those strings that end with this symbol and that we haven't encounter yet).  
Taje a string t = s + c and invert it. Our task is now count how many prefixes of t are not found anywhere else in t. Let's compute the Z-function of t and find its maximum value $z_max$. Obviously, t's prefix of length $z_max$ occurs also somewhere in the middle of t. Clearly, shorter prefixed also occurs.  
So our answer will be: `k += t.size() - z_max`  
**String compression**  
> Given a string s of length n. Find its shortest "compressed" representation, that is: find a string t of shortest length such that s can be represented as a concatenation of one or more copies of t.  
A solution is: compute the Z-functon of s, loop through all i such that i divdes n. Stop at the first place such that i + z[i] = n. Then, the string can be compressed to the length i.  
## Practice problems:
### **1.[Chef and String](https://www.codechef.com/problems/CHSTR)**  
> Given a string with length n, count how many ways that way the we can choose k substrings that is equal.  

The idea of the problem is, similar with the problem that you have to count how many different substrings.  
Call cnt[i] is the number of at least i substrings are equal.  
Now we call Z functions n times for suffix P = S[i..N-1].  
With each string P, we realize that it is possible to calculate cnt[i] by it.  
For example Z function of P = S[0..N-1] = "ababa".  
We have:  
+ Z[1] = 5  
+ Z[2] = 0  
+ Z[3] = 3  
+ Z[4] = 0  
+ Z[5] = 1  
From the above array we can conclude that we have 1 substring which can be choosen atleast 3 times. Why ? because there are 3 entries array that are greater than or equal to 1.  
Similarly we can deduce for 2 (2 times), 3 (2 times), 4 (1 time ) and 5(1 time).  
So we increment cnt[3] once, cnt[2] twice and cnt[1] twice.  
Now problem is calculate exactly how many substring can be choose exactly i times. Base on simple math, we have: `cnt[i]-cnt[i+1]`.  
![Source code](./CHSTR.cpp)  











