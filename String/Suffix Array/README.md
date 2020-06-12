# Suffix Array  
## **Definition**    
Let s be a string of length n. The i-th suffix of s is the substring s[i..n-1].  
A **suffix array** will contain integers that represent the **starting indexes** of all the suffixes of a given string, after the aforementioned suffixes are sorted.  
As an example look at the string s = abaab, All the suffixes are as follows:  
- 0. abaab    
- 1. baab   
- 2. aab   
- 3. ab  
- 4. b  

After sorting these strings:  
- 2. aab  
- 3. ab  
- 0. abaab    
- 4. b  
- 1. baab  
Therefore the suffix array for s will be (2,3,0,4,1).  
As a data structure it is widely used in areas such as data compression, bioinformatics and, in general, in any area that deals with strings and string matching problems.  
## **Construction**    
### **O($n^2 log(n)$) approach**  
This is the most naive approach. Get all the suffies and sort them using quicksort or merge sort.  
### **O(n log(n)) approach**  
Strictly speaking, the following algorithm will not sort the suffixes, but rather the cyclic shilfs of a string. However we can very easily derive an algorithm fr sorting suffixes from it: it is enough to append an arbitrary character to the end of the string which is smaller than any character from the string(normally, It would be $).  
Then the order of the sorted cyclic shilfs is equivalent to the order of the sorted suffixed, as demonstrate here with the string dabbb.  
- 1. abbb$d bbb  
- 4. b$dabb b  
- 3. bb$dab bb  
- 2. bbb$da bbb  
- 0. dabbb$ dabbb  

Since we are going to sort cyclic shilfs, we will consider **cyclic substrings**. We will use the notation s[i...j] for the substring even with i > j (s[i..j] = s[i...n-1] + s[0...j]).  
The algorithm we discuss will perform [log(n)] + 1 iterations. In the k-th iteration (k = 0...[log(n)]) we sort the n cyclic substrings of s of the length $2^k$. After the log[n]-th iteration the substrings of length $2^{[log(n)]} \geq n$ will be sorted, so this is equivalent to sorting the cyclic shilfs altogther.  
In each iteration of the algorithm, in addition to the permutation p[0...n-1], where p[i] is the index of i-th substring (starting at i and with length 2^k) in the sorted order, we will maintain an array c[0...n-1], where c[i] corresponds to the **equivalent class** to which the substring belongs. Because some of the substrings will be identical, and the algorithm needs to treat them equally. For convenience the classes we be labeled by numbers started from zero.  
In addition the number c[i] will be assigned in such a way that they preserve information about the order: If one substring is smaller than the othe, then it should also have a smaller class label. The number of equivalence classes will be stored in a variable classes.  
Let's look at an example. Consider the string `s = aaba`. The cyclic substrings and the corresponding array p[] and c[] are given for each iteration.  
0: (a,a,b,a) --> p = (0,1,3,2), c = (0,0,1,0).  
1: (aa,ab,ba, aa) --> p = (0,3,1,2), c = (0,1,2,0).  
2: (aaba, abaa, baaa, aaab) --> p = (3,0,1,2), c = (1,2,3,0).  
It is worth noting that the value of p[] can be different. For example in the 0-th iteration the array could also be p = (3,1,0,2) or p = (3,0,1,2). All these options permutation the substrings into a sorted order. So they are all valid. At the same time the array c[] is fixed.  
Let us focus on the implementation of the algorithm. We will write a function that takes a string s and returns the permutations of the sorted cyclic shifts.  
```
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
```  
At the beginning (in the **0-th iteration**) we must sort the cyclic substrings of length 1, that is we have to sort all characters of the string and divide them into equivalence classes (same symbols get assigned to same class). The can be done trivially, for example, by using **counting sort**. For each character we count how many times it appears in the string, and then use this information to create the array p[]. After that we go through the array p[], and construct c[] by comparing adjacent characters.  
```
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
```  
Now we have to talk about the iteration step. Let's asume we have already performed the k-1 th step and computed the values of the arrays p[] and c[] for it. We want to compute the values for k-th step in O(n) time.  
To do this, note that the cyclic substrings of length $2^k$ consists of two substrings of length $2^{k-1}$ which we can compare with each other in O(1) using the information from the previous phase. It works similar with RMQ algorithm.  
This gives us a very simple solution: **sort** the substrings of length $2^k$ by these pairs of numbers. This will give us the required order p[].  
But how do we quickly perform such a sorting of the pairs. Since the element of the pairs do not exceed n, we can use counting sort again. However sorting pairs with counting sort is not the most efficient. To achieve a better hidden constant in the complexity, we will use **radix sort**.  
To sort the pairs we first sort them **by the second element**, and then by the first element (with a stable sort i.e sorting without breaking the relative order of equal elements). However, the second elements were already sorted in the previous iteration. Thus, in order to sort the pair by the second elements, we just need to subtract $2^{k-1}$ from the indices p[](e.g if the smallest substring of length $2^k-1$ start at position i, then the substring of length $2^k$ with smallest second half start at **i-$2^{k-1}$**.  
So only by simple subtractions we can sort the second elements of the pairs in p[]. Now we need to perform a stable sort by the first element. As already mentioned, this can be accomplished with counting sort.  
The only thing left is to compute the equivalance classes c[], but as before we this can be done by simply iterating over the sorted permutation p[] and comparing neighboring pairs.  
Here is the remaining implementation. We use temporary arrays pn[] and cn[] to store the permutation by the second elements and the new equivalent class indices.  
**__Note:__**  
The idea of **radix sort** is sort from the **least important elements to the most important element**.  
For example: we have 5 numbers: 405, 123, 213, 230, 900  
In the first step, we sort according to the last digit: then we have:  
230, 900, 123, 213, 405.  
In the second step, we sort according to the last two digits: 900, 405, 213, 123, 230.  
In the last step, we get the answer by sort the last 3 digits: 123,213,230, 405, 900.  
Highly recommend to watch this: [Radix sort](https://www.youtube.com/watch?v=YXFI4osELGU)  
```
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
```  
## **Application**.    
### **Finding the smallest cyclic shift**    
The algorithm above sorts all cyclic shifts (without appending a character to the string), and therefore p[0] gives the position of the smallest cyclic shilf.  
### **Finding a substring in a string**    
> Your task is to find a stirng s inside some text t online - we know the text t beforehand, but not string s.  

We can create the suffix array for the text t in O(tlog(t)) time.  
By applying binary search, we can find string s in O(slog(t)) time.  
Notice that if the substrings occurs multiple times in t, the all occurences will be next each other in p. Therefore, the number of occurences can be found with a second binary search, and all occurences can be printed easily.  
### **Compare two substrings of a string**  
> We want to compare two substrings of same length of a given string s in O(1) time, i.e. checking if the first substring is smaller than the second one.  
Similar to RMQ, we construct suffix array in O(|s|log(|s|)) time and store all the intermediate results of the equivalence classes c[].
```
int compare(int i, int j, int l, int k) {
    pair<int, int> a = {c[k][i], c[k][(i+l-(1 << k))%n]};
    pair<int, int> b = {c[k][j], c[k][(j+l-(1 << k))%n]};
    return a == b ? 0 : a < b ? -1 : 1;
}
```  
### **Longest common prefix of two substrings with additional memory**  
> For a given string s we want to compute the longest common prefix (LCP) of two arbitrary suffixes with position i and j.  
```
int lcp(int i, int j) {
    int ans = 0;
    for (int k = log_n; k >= 0; k--) {
        if (c[k][i] == c[k][j]) {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}
```  
Here log_n denotes a constant that is equal to the logarithm of n in bases 2 rounded down.  
### **Longest common prefix of two substrings without additional memory**  
We have the same task as in the previous section.  
Unline the previous method, this one will only use O(|s|) memory. The result of preprocessing will be an array (which itself is an important source of information about the string). LCP queries can be answered by performing RMQ quieries in this array, so for different implementation it is possible to achieve logarithmic and even constant query time.  
The basic for this algorithm is we will compute the longest common prefix for each **pair of adjeacent suffixes in the sorted order**. In the other words we construct an array lcp[0...n-2] where lcp[i] is equal to the length of the longest common prefix of the suffixes starting at p[i] and p[i+1].  
Then the answer for two arbitrary two suffixes, not necessarily neighbor ones, can be obtained from this array. In fact, let the request be to compute the LCP of the suffixes p[i] and p[j]. **Then the answer will be min(lcp[i],...lcp[j-1]).**    
Thus if we have such an array lcp, then the problem is reduced to the RMQ, which has many wide number of different solutions with different complexities.  
So the main task is to **build** this array lcp. We will use **Kasak's algorithm**, which can compute this array in O(n) time.  
Let's look at two adjacent sufixes in the sorted order(order of the suffix array). Let their starting positions be i and j and their lcp equal to k > 0. If we remove the first letter of both suffixes i.e. we take the suffixes i+1 and j+1, then it should be obvious that the lcp of these two is k-1. However, we cannot use this value and write it in the lcp array because  these two suffixes might not be next to each other in the sorted order. The suffix i+1 will of couse be smaller than the suffix j+1, but there might be some suffixes between them. However, since we know that LCP between two suffixes is the minimum value of all transitions, we also know that the LCP between any two pairs in that interval has to be at least k-1, especially between i+1 and the next suffix. And possibly it can be bigger.  
Now we already can implement the algorithm. We will iterate over the suffixes in order of their length. This way we can reuse the last value k, since going from suffix i to the suffix i+1 is exactly the same as removing the first letter. We will need an additional array rank, which will give us the position of a suffix in the sorted list of suffixes.  
```
vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
```  
It is easy to see, that we decrease k at most O(n) times(each iteration at most once, except for rank[i] == n-1), where we directly reset it to 0, and the LCP between two strings is at most n-1, we will also increase k only O(n) times. Therefore the algorithm runs in O(n) time.  
### **Number of different substrings**  
WE preprocess the string s by computing the suffix array and the LCP array. Using this information we can compute the number of different substring.  
To do this, we will think about which **new** diffrent substrings begin at position p[0],p[1]...  
Because the suffixes are sorted, it is clear that the current suffix p[i] will give new subbstrings for all its prefixes, except for the prefixs that conciade with the suffix p[i-1]. Thus all its prefixes except the first lcp[i-1] one one. Since the length of the current suffix is n - p[i], n - p[i] - lcp[i-1] new suffixes start at p[i]. Summing over all the suffixes, we get the final answer.  

$$ \sum_{i=0}^{n-1} (n-p[i]) - \sum_{i=0}^{n-2} lcp[i] = \frac{n^2 + n}{2} - \sum_{i=0}^{n-2} lcp[i] $$
















