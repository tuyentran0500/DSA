# Codeforces
Unresolved problems in Codeforces/SPOJ, etc ...

### Educational Round 73E
1. Problems statement:
- having many collumns, collumn i have a height h[i].
- Alice and Both plays a game, Alice play first.
- In Alice's turn, he can choose a collumn has h[i] >= a, replace it with two columns which sum is equal to h[i] - a;
- In Both's turn, he can choose a collumn has h[i] >= b, replace it with two columns which sum is equal to h[i] - b;
- Find the winner.
2. Solution:
- Divide these collumns in 4 group according to their heights:
	+ 1. h[i] < b.
	+ 2. b <= h[i] < a.
	+ 3. a <= h[i] < 2b.
	+ 4. len >= 2b;
- Note that if one of these collumns belongs to group 2, then Both wins.
- Also, when Alice takes turns, she does not want any of these collumns belong group 4 either, because Both can turn group 4 into 1 collumns in group 2.
- Therefore, if we have two or more collumns in group 4, Both wins.
- In case number_collumns_group4 <= 1: we will use brute-force to find the solution.   