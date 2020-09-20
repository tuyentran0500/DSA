# DSA project  
## made by Tuyen.  
**Note:** The work is insprired by many algorithm websites (including: VNOI, cp-algorithms, ...).  
## Recommend exercise 5/2017:  
+ https://www.hackerrank.com/challenges/stockmax stockmax - siêu bựa  
+ https://www.hackerrank.com/challenges/square-subsequences - first difficult mình làm được hihi :v  
+ http://vn.spoj.com/problems/PTREE/ _ SOL : (Độc ác).    
Có công thức QHĐ f[i][j] → là cost max thu được từ cây con đỉnh i và gồm j phần tử.  
Do đó f[i][j] = max( f[i][z] + f[v][i - z] )  ( z là con của i )  
Thực hiện việc này trong hàm dfs và lưu ý thử tự: khi for thì for i từ p → 1 . Vì đề phòng trường hợp bị trùng .  
trace xây khá bựa : lưu ý phần cha con.  

**Exercise of the month 5**: PTREE spoj  

## Recommend exercise 6:    
+ [NTSEQ spoj](http://vn.spoj.com/problems/NTSEQ/) :  Một dạng mới trong BIT  
+ http://codeforces.com/contest/282/problem/E :Xúc xích tình yêu . Dạng tiêu biểu hóa của Trie + bitmask  
+ http://codeforces.com/problemset/problem/592/D : Tìm siêu trung điểm  
+ https://contest.yandex.com/algorithm2016/contest/2540/problems/C/ : DP sáng tạo  
http://vn.spoj.com/problems/GSS/ - segment tree ..  

**Exercise of the month 6**: NTSEQ  
## Recommend exercise 7:  
+ http://main.edu.pl/en/archive/pa/2009/wie - Dp + IT + nhận xét khủng  
+ http://main.edu.pl/en/archive/pa/2009/kns - toán sơ cấp  
+ [NUMSET codechef](https://www.codechef.com/problems/NUMSET) - Chia block cơ bản + DP. Khá hay  
+ http://codeforces.com/problemset/problem/690/C3 - Bài toán lạ sử dụng dạng năng động hơn của cây, khá mới mẻ mang tầm vóc lớn =))  
+ http://tjsct.wikidot.com/usaco-feb08-gold - Hotel → ranger tree  

**Exercise of the month 7**: NUMSET   
## Recommend exercise 8:  
+ [and xor or](https://www.hackerrank.com/challenges/and-xor-or) - biến đổi công thức kì diệu + kagain  
+ [GMATRIX](http://www.spoj.com/problems/GMATRIX/) - Đồ thị ẩn  
+ [USACO](http://usaco.org/index.php?page=viewproblem2&cpid=365) - qhđ trên it  
+ [NKPOLICE](http://vn.spoj.com/problems/NKPOLICE/) - Đồ thị hay: Euler tour  +  dfs định hướng  
+ [CF 703D](http://codeforces.com/contest/703/problem/D) - BIT + dquery + khả năng cao giúp solve được gss2  
+ [MOOD spoj](http://www.spoj.com/DUTUYEN/problems/MODD/) - Nhận xét hay
+ [CF86D](http://codeforces.com/contest/86/problem/D) -MO algorithrm   
+ http://main.edu.pl/en/archive/oi/17/pil - stack → Mink  
+ [PATULJCI](http://vn.spoj.com/problems/PATULJCI/) - 2 cách vô cùng độc đáo : IT và rand  
+ [CF 710E](http://codeforces.com/contest/710/problem/E) - không khó nhưng giúp nhắc lại tác dụng của deque  
+ Chứng minh công thức Catalan → hay 
+ [CF128C](http://codeforces.com/contest/128/problem/C) - tổ hợp  
+ [429C](http://codeforces.com/problemset/problem/429/D) -closest pair  
+ [CF 321E](http://codeforces.com/contest/321/problem/E) - qhd + opt  
**Exercise of the month 8**: Tricky function  
## Recommend exercise 9:  
+ [KKDD spoj](http://vn.spoj.com/problems/KKDD/) - bit + qhđ :o  
+ https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3540 - Rút gọn QHĐ  
+ [QTREE5](http://www.spoj.com/problems/QTREE5/) - tác hại của del multiset  
+ [HEAP1](http://vn.spoj.com/problems/HEAP1/) - huffman tree  
**Exercise of the month 9**: HEAP1  
## Recommend exercise 10:  
+ [CF706E](http://codeforces.com/problemset/problem/706/E) - 1 cách giải bài toán 2D  
+ http://www.iarcs.org.in/inoi/online-study-material/problems/roads-soln.php - Cây khung  
+ [CF 723E](http://codeforces.com/contest/723/problem/E) - Euler cycle + tính chất cơ bản  
+ http://codeforces.com/gym/100624/attachments / D - non_boring  
+ [CF 484E](http://codeforces.com/contest/484/problem/E)  - PIT + thuật khủng  
+ [PERSHFTS](https://www.codechef.com/OCT15/problems/PERSHFTS) - xét mod 2 cơ bản  
+ [CF 377D](http://codeforces.com/problemset/problem/377/D) - sweep line 2D → 1D  
**Exercise of the month 10**: Developing game  
## Recommend exercise 11:
+ matrixsearch _ QN5  
+ http://hsin.hr/coci/archive/2006_2007/contest1_tasks.pdf - debug  
+ adict - AH  
+ FIBWORD - 23/11/ Thầy Thuận  
+ http://hsin.hr/coci/archive/2015_2016/contest7_tasks.pdf - Prokletnik  
+ https://www.hackerrank.com/contests/hourrank-14/challenges/lilys-homework  
**Exercise of the month 11:** Matrix search  
## Recommend exercise 12  
+ http://main.edu.pl/en/archive/pa/2011/bio  
+ [CF 741C](http://codeforces.com/contest/741/problem/C)  
+ [CF 611F](http://codeforces.com/contest/611/problem/F)    
+ [CF 749E](http://codeforces.com/contest/749/problem/E)    
+ [VOIEXAM](http://vn.spoj.com/problems/VOIEXAM/)  
+ [CF 724E](http://codeforces.com/contest/724/problem/E)     
# I am back !!!.  
## Recommend exercise 7/2020:  
+ [ABC 172E](https://atcoder.jp/contests/abc172/tasks/abc172_e) - inclusive and exclusive theorems  
+ [LIS on Tree - ABC165F](https://atcoder.jp/contests/abc165/tasks/abc165_f) - LIS(using binary search) and rollback technique.  
+ [Number of components](https://codeforces.com/contest/1151/problem/E) - math + nice comment. --> Contribution to the sum.  
+ [Microtransactions](https://codeforces.com/contest/1165/problem/F2) - Binary search + greedy.  
+ [Active Infants](https://atcoder.jp/contests/abc163/tasks/abc163_e) - Nice problem + ignore the `abs()` notation and dp from both sides. --> Look closer to the example.  
+ [Don't be a subsequence](https://atcoder.jp/contests/arc081/tasks/arc081_c) - DP + `nxt table` + Nice observation.  
+ [Small Products](https://atcoder.jp/contests/abc132/tasks/abc132_f) - DP + square root --> Optimize the complexity.  
+ [Or Plus Max](https://atcoder.jp/contests/arc100/tasks/arc100_c) - For all subsets.  
+ [Underground Lab](https://codeforces.com/contest/780/problem/E) - Euler tour + 2*n + 1 vertices --> make a tree into an array.  

Working list:     

- [Substitutes in Number](https://codeforces.com/contest/464/problem/C)   

- [Game of Stones](https://codeforces.com/contest/768/problem/E)  

Problem lists (updated in 20/9)  
- [100 challenges](https://docs.google.com/spreadsheets/d/11VqPaHAPi7kqY-x3ZlusYSk7vVmG8ZtiUWIla1AzhvU/edit#gid=1386834576)  
Reading List:
- http://tamlyhoctoipham.com/lam-the-nao-de-khong-quen-nhung-gi-da-hoc?fbclid=IwAR1T-ryutSOu_G-YSnWztiuEItvKnz73mHreaUFQD3o9-Ib7cNV6YtHfHkM  

- https://codeforces.com/blog/entry/20284  
- https://codeforces.com/blog/entry/60003  

**Solution zone:**  
Thus, we finally want to ask the question, "After inserting all N colors of balls into the row, we want there to be 0 bad spaces. How many ways are there of doing this?".  
We can answer this question using DP. Indeed, let dp[x][y]:= the number of ways inserting balls of the first x colors in such a way that there are exactly "y" bad spaces 
We have that initially dp[0][0] = 1, dp[0][y] = 0;
Then, given that we have filledin colors upto x, we try to insert C[x+1] balls. Note that the total number of spaces prior to insertion is 1 + c[1] + C[2] + C[3] +... + c[x], (lets denote this sum is spaces[x]). From a dp[x][y] state, we have y "bad" space and space[x] - y = z good spaces.  
We choose i good spaces and j bad spaces into which to insert C[x+1] balls. (naturally C[x+1] >= x+y). What will this state look like? Each ball that is inserted into a "Bad" space will destroy that bad space. Each ball that is inserted into a "good" space will remain good. Each of other balls will create a "bad" space upon insertion. Hence, the number of bad spaces will become (y - j) + (C[x+1] - i -j).  
We finally need to measure how much will DP[x][y] contribute to the new state. We firsts choose i good spaces from z(=spaces[x]-y), and j bad spaces from y. This brings bout a cotribution comb(z,i) * comb(y,j).  
Just choosing the possible locations is not enough however. In our example we need to have from "+1-1-1-1-1+" case, two different cases "+2-21-1+2+1-1+" and "+2+1-1-1+2-2+1-1+". Just by choosing which is good and bad spaces to insert balls would treet the above two as the same.  


  












 
