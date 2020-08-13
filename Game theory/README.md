Link to study:  
- [Let us code](http://letuskode.blogspot.com/2014/08/grundy-numbers.html)  
- [Game theory](https://www.math.ucla.edu/~tom/Game_Theory/comb.pdf)  

# Sprague-Grundy theorem. Nim  
## Introduction  
This theorem describes the so-called **impartial** two player game, i.e. thoese in which the available moves and winning/losing depends only on the state of the game. In other words, the only difference between the two player is that one of them moves first, and they play optimally.  
Such games can be completely described by a DAG.  
Since there are no draws, we can classify all game states as either **winning** or **losing**.   
Our task is to classify the states of a given game.  
The theory of such games was independently developed by Roland Sprague in 1935 and Patrick Michael Grundy in 1939.  
## Nim  
### Game description.  
> There are several piles, each with several stones. In a move a player can take any positive number of stones from any one pie and throw them away. A player loses if they can't make a move, which happens when all the piles are empty  
### The solution.  
The solution by Charles L.Bouton looks like this:  
**Theorem:** The current player has a winning strategy if and only if the xor sum of the pile sizes is non-zero. The xor-sum of a sequence a is `a1 xor a2 ... xor an`  
**Proof:**  
The key of the proof is the presence of a **symmetric strategy for the opponent**. We show that a once in a position with the xor-sum equal to zero, the player won't be able to make it non-zero in the long-term - if they transsition to a position with a non-zero sum, the the opponent will always have a move returning the xor-sum back to zero.  
We will prove the theory by mathetical induction.  
For an empty Nim, the xor-sum is already zero and the theorem is true.  
Now suppose we are in a non-empty state. Using the assumption of induction, we assume that the theorem is proven for all states reachable from the current one.  
The the proof splits into two parts: if for the current position the xor sum s = 0, we have to prove that this state is losing i.e. all reachable states have xor-sum `t != 0` if `s != 0`, we have to prove that there is a move leading to state with `t = 0`.  
+ Let `s=0` and let's consider any move. This move reduces the size of a pile x to a size y.  
Since y < x, `y xor x` can be zero, so `t!=0`. That means any reachable state is a winning one, so we are in a losing position.  

+ Let `s != 0`. Consider the binary representation of the number s. Let d be the number of its leading (biggest value) non-zero bit. Our move will be on a plie whose size's bit number is set (it must exisst, otherwise the bit wouldn't be set in s). We will reduce its size x to y = `x xor s`. All bits at positions greater than d in x and y match and bit d is set in x but not set in y. Therefore, y < x, which is all we need for a move to be legal. Now we have:  
```
t = s xor x xor y = s xor x xor (s xor x) = 0
```  
This means we found a reachable losing state (by the assumption of induction) and the current state is winning.  

**Corollary.** Any state of Nim can be replaced by an equivalent state as long as the xor-sum doesn't change. Moreover, when analyzing a Nim with several piles, we can replace it with a single pile of size s.  
## The equivalence of impartial games and Nim (Spargue-Grundy theorem)  
Now we will learn how to find, for any game state of impartial game, a corresponding state of Nim.  
### Lemma about Nim with increases  
We consider the follwoing modification to Nim: we also allow **adding stones to a chosen pile**. The exact rules about how and when increasing is allowed **do not interest us**, however the reuls should keep our game **acyclic**. In later sections, example games are considered.  
**Lemma.** The addition of increasing to Nim doesn't how winning and losing states are determined. In other word, increases are useless, and we don't have to use them in a winning strategy.  
**Proof** Suppose a player added stones to a pile. Then his opponent ca simply undo his move - decrease the number back tot he previous value. Since the game is acyclic, sooner or later, the current play won't be able to use an increase move and will have to do the usual Nim move.  
### Sprague-Grundy theorem  
Let's consider a state v of a two-player impartial game and let $v_i$ be the states reachable from it (where i $\in \{1,2,3...k\}, k \geq 0$). To this state, we can assign a fully equivalent game of Nim with one pile of size x. The number x is called the Grundy value of num-value of state v.  
Moreever, this number can be found in the following recursive way:  

$$ x = mex \{x_1,x_2,...x_k\} $$

Where $x_i$ is the Grundy value for state $v_i$, and the function mex (minimum excludant) is the smallest non-negative integer not found in the given set.  
Viewing the game as a graph, we can gradually calculate the Grundy values starting from vertices without outgoing edges. Grundy value being equal to zero means a state is losing.  
**Proof** We will use a proof by induction.  
For vertices without a move, the value x is the mex of and empty set, which is zero. That is correct, since an empty Nim is losing.  
Now consider any other vertex v. By induction, we assume the value $x_i$ corresponding to its reachable vertices are already calculated.  
Let p = $mex\{x_1...x_k\}$. Then we know that for any integer $i \in [0, p)$ there exists a reachable vertex with Grundy value i. This means v is **equivalent to a state of the game of nim with increases with one pile of the size p**  
In such a game we have transitions to piles of every size smaller than p and possibly transitions to piles with sizes greater than p. Therefore, p is indeed the desired Grundy value for the currently considered state.  










