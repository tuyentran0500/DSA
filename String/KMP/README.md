# Knuth-Morris-Pratt algorithm.  
## Prefix function defition.  
> You a given a string s of length n. The prefix function is defined as an array p of length n, where p[i] is the length of the longest proper prefix of the substring s[0..i]. A proper prefix of a string is a prefix that is not equal to the string itself. By definition p[0] = 0.  
## Trivial algorithm  
```
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    return pi;
}
```  
**Note:** The following code belongs to [CP-algorithm website](https://cp-algorithms.com/string/prefix-function.html)  

## Efficient Algorithm.  
### **First optimization**.  
The first observation is, that the values of the prefix function can only increase by at most **one**.  
Thus, when moving to the next position, the value of the prefix function can either increase by one, stay the same, or decrease by some amount. This allows algorithm run in $O(n^2)$.  
### **Second optimization**.    
Let's go further, we want to get rid of the string comparisons. To accomplish this, we have to use all the information computed in the previous steps.  
If s[i+1] = s[p[i]]: then we can say that p[i+1] = p[i] + 1
else: We need to try shorter string. In order to speed things up, we would like to immediately move to the longest length j < p[i], such that prefix property in the position i holds s[0...j-1] = s[i-j+1....i]  
we can find that using the p[i].  
Source code:  
```
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
```  
## Application  
### 1. Search for a substring in a string. The Knuth-Morris-Pratt algorithm.    
> Given a text t and a string s, we wabt to find aand display the positions of all occurences of the string s in the text t.  

**Solution**  
We need to form a new string s + # + t, and our question is now simple as we need to find all the p[i] >= s.size().  
Thus the Knuth-Morris-Pratt algorithm solves the problem in O(n + m) time and O(n) memory.  
Practice: [SUBSTR spoj](https://vn.spoj.com/problems/SUBSTR/)  
Source code:
```
void solve(){
	int m = b.size();
	int curP = 0;
	s = b + "#" + s;
	for(int i=1;i<s.size();++i){
		int j = curP;
		while (j > 0 && s[i] != s[j]) 
			j = cur[j-1];
		if (s[i] == s[j]) j++;
		curP = j;
		if (i <= m) cur[i] = curP;
		if (curP == m) cout << i - 2*m + 1 << ' ';
	}
}
```  
### 2. Counting the number of occurences of each prefix.  
> Counting the number of prefix s[0...i] occurs in string s.  

You can solve this problem by using the way you use to search for a substring.  
Generally, at position i, you want to count how many prefix s[0...j] that occurs and end at s[i]. Therefore, we have a source code.  
```
vector<int> ans(n + 1);
for (int i = 0; i < n; i++)
    ans[pi[i]]++;
for (int i = n-1; i > 0; i--)
    ans[pi[i-1]] += ans[i];
for (int i = 0; i <= n; i++)
    ans[i]++; // Counting the prefix itself.  
```  
If we have another problem, we need to counter how many time a prefix s[0...i] occurs in a string k.  
We use the same trick, create a new string s + "#" + k.  
### 3. The number of different substring.  
> Given a string s, compute the number of different substring within s.  

We will solve this problem iteratively. Namely we will learn, knowing the current number of different substrings, how to recompute this count by adding a character to the end.  
So let k is the current number of different substrings in s, and we add the character c to the end of s. Obiviously some new substrings ending in c will appear. We want to count the new substring that didn't appear before.  
Let call t = s + c, and reverse t, our problem becomes counts how many prefix that didn't appear before.  
call maxPi = max(p[i]) within t. then the prefix with size maxPi + 1...s will not appear anywhere before.  
--> ans += s.size() + 1 - maxPi.  
So for each character appended we can compute the number of new substrings in O(n) times, which gives a time complexity of O(n^2) in total.  
It is worth noticing, that we can also compute the number of different substrings by appending the characters at the beginning, or by deleting characters from the beginning or the end.  
### 4. Compressing a string.  
> Given a string s of length n. We want to find the shortest "compressed" representation of the string, i.e. we want to find a string t of smallest length such that s can be represented as a concatenation of one or more copies of t.  

[Exercise](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396)  
You can prove the answer for this problem is n - p[n-1] by relying on the fact that string s is a concatenation of one or more copies of t.  
[Source code](./UVA455.cpp) 






