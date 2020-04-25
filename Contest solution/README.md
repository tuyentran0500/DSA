# Codeforces
Unresolved problems in Codeforces/SPOJ, etc ...

## [**Educational Round 73E**](https://codeforces.com/contest/1221/problem/E)
### **1. Problem statement**    

> Having many collumns, collumn i have a height h[i].  
Alice and Both plays a game, Alice play first.  
In Alice's turn, he can choose a collumn has h[i] >= a, replace it with two columns which sum is equal to h[i] - a;  
In Both's turn, he can choose a collumn has h[i] >= b, replace it with two columns which sum is equal to h[i] - b;  
Find the winner.  

### **2. Solution:**    
Divide these collumns in 4 group according to their heights:  
	+ 1. h[i] < b.    
	+ 2. b <= h[i] < a.    
	+ 3. a <= h[i] < 2b.   
	+ 4. len >= 2b;   
Note that if one of these collumns belongs to group 2, then Both wins.  
Also, when Alice takes turns, she does not want any of these collumns belong group 4 either, because Both can turn group 4 into 1 collumns in group 2.  
Therefore, if we have two or more collumns in group 4, Both wins.  
In case number_collumns_group4 <= 1: we will use brute-force to find the solution.  
[Source code](./Edu73E.cpp)  

## [**Codeforces 442 Div1 A. Bonrya and Hanabi**](https://codeforces.com/problemset/problem/442/A).  
### **1. Problem statement**    
> Overall, the Hanabi game has 25 types of cards (5 distinct colors and 5 distinct values).  
Borya is holding n cards. The game is somewhat complicated by the fact that everyone sees Borya's card except himself.  
Borya knows which cards he has but he knows nothing about the order they lie in. (Note that he might have multiple indentical cards).  
The aim of the other players is to achieve the state when Boryas knows the color and number value of each of his cards.  
For that, other players can give him hints:  
	+ Color hint: A player names some color and points at all the cards of this color.  
	+ Value hint: Similar to Color hint, a player names some color and points at the cards that contains the values.  
Goal: Determine the minimize number of hints to help Borya find the order of his cards.  

### **2. Solution:**     
Notice that we have up to 10 hints and the order of hints is not matter. Therefore, we could run 2^10 gameplay. In each game play, we need to know that If Borya could distingush different cards in this gameplay.  
[source code](./442A.cpp)  
## [Codeforces 340E Div2. Iahub and Permutations](https://codeforces.com/problemset/problem/340/E).    
### **1. Problem statement**    
> Iahub is so happy about his achievement, but Iahubina doesn't.  
Therefore, she decides to destroy the array that Iahub made.  
We have a array of length n, it is guarantee that a[k] != k.  
However, some numbers were deleted in the array, and your mission is find the number of way to recover the array without existing a place k <= n that a[k] == k.  
**Note:** a[k] = -1 when the k-th number was deleted.  
**Constrains:**  
	+ n <= 2000.  
	+ Iahub's array is a permutation of n distinct number 1,2,....n.  

### **2. Solution:**    
Definition:  
	+ "free position" - a position which has -1 value.  
	+ D is a set of all deleted elements.  
Clearly, we observe that some elements from D can appear on all free positions of permutation, without create a fixed point, while other aren't.  
Let dp(n,k) = in how many ways can i fill (n+k) free position, such that:  
	+ n elements can be placed anywhere.  
	+ k elements can be placed anywhere except a fixed position.  
If k = 0 --> dp(n,0) = n!.  
Also, we can calculate dp(n,1) = n! * n. This means we are not allowed to place an element in a position out of (n+1) free positions, however we can put it in n other position.  
Our goal is calculate dp(n,k).  
We have two cases:  
	+ Choose a number which can be placed anywhere in order to reduce number of places can form a fixed point.  
	+ Choose a number from those which can form a fixed point with the same goal as the first case.  
__Case 1:__  
Suppose X is the first position, such as in the set of k numbers there exist one which cannot be placed there (because it will make a fixed point). In this case, we complete position X with one of n numbers. This will make number equal to X from the k numbers can be placed anywhere. In other way, we loose one number that can be placed anywhere but also gain one number.  
Therefore: dp(n,k) += dp(n,k-1)  
__Case 2:__  
In this case, position X will be completed with one number from the k numbers set. All numbers which can form fixed points can appear there, except number having value equal to X. So there are k-1 of them. We choose arbitrary number Y from those k-1 numbers. As a result, we "loose" 2 numbers can form a fixed point but also gain a number can place anywhere X.  
--> dp(n,k) += (k-1) * dp(n+1, k-2)  
[Source code](./340E.cpp)  
### [**Codeforces 442 C Artem and Array**](https://codeforces.com/problemset/problem/442/C).  
#### 1. Problem statement.  
Artem has an array of n positive integers and he decides to play with it.  
The game contains n moves. Each move goes like this:   
Artem choose a number in array and remove it. For that, he gets min(a,b) points where a and b are numbers that were adjacent with the removed number. If the number doesn't have an adjacent number to the left/right, he will get 0 score.  
Maximize the score that he might have.  
**Constraints:**  
	+ n <= 5 * 10^5.  
	+ 1 <= a[i] <= 10^6   
#### 2.Solution.  
It's obvious that we should never delete the first and the last elements of array.  Let's look at minimum number.  
Let it be x and there are n elements in the array. We can subtract x from all elements and the answer for the problem will decrease (n-2) * x.  
If the minimal element was the first or the last one, we can't count to it now (it's equal to 0, so it will not affect the answer now).  






