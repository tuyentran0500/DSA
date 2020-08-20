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
## Sprague-Grundy theorem  
Link to study: [Samidavies blog](https://samidavies.wordpress.com/2016/05/28/the-sprague-grundy-theorem/?fbclid=IwAR22OXm5uFu6nPreGpzrsUV6XfYXBBYcOqF4jqJUgEHfo6t8jsGGts-uu9k)  
### Background  

$$mex(N) = min\{ x \in Z_geq0 : x \notin N\}$$  
= The smallest nonnegative integer that is not an element in N.  
### Game as graphs  
A game can be represented as a graph when the vertex set is the set of positions in the game, and there exists a directed edge between x and y if a player can move from position x to y.  
In normal play, the loser of a game is the person who ends at the vertex wich has no out edges.  
So given a game $X = (V, f)$ there is a position set V and a function f, where for each $v \in V, f(v)$ is the possible positions to move to from v. f(v) is called the set of **followers** of v.  

![img](https://samidavies.files.wordpress.com/2016/05/ttt2graph1.png?w=768)  
On a game $X = (V, f)$, the **Sprague-Grundy function is defined as g : $V \rightarrow Z_\geq0$ where:  
$$ g(v) = min\{ j \geq 0 : j \neq g(x) for:x \in f(v)\} = mex\{ g(x) for: x \in f(v) \}$$
So the Sprague-Grundy function inputs a position v and looks at the set of Sprague-Grundy values of v's followers. The function returns the smallest nonnegative integer which is not in the set of Sprague-Grundy values of v's followers.  

### Combining games  
Looking at a big game where there are tons of positions available is difficult. To overcome this, the big game can be broken into a bunch of smaller games, and then combining them back together, is much easier.  
Denote the k smaller games as:  
$$G_1 = (V_1, f_1), G_2 = (V_2, f_2),... G_k = (V_k,f_k)$$  
The big game is called the **disjuctive sum** or **combined game** of the k smaller ganes. Let the big game be denoted as G, and define it as:  
$$G = G_1 + G_2 + ... + G_k = (V, F), where, V = V_1 x V_2 x ... V_k, f = f_1 x f_2 x ... x f_k$$  
In the combined game, $u=(u_1, u_2, ... u_k) \in V$ is a follower of v = (v_1, v_2, v_k) \in V$ exactly when there is some $i* \in [k]$ such that $f(i*)*(v_*i) = u_i$ and for all $i \in [k]# such as $i \neq i*, v_i = u_i$.  
### Equivalent positions.  
As stated in the beginning of this post, the whole objective here is to prove that two games are equivalent. So let's define the notion of equivalent position in the games. Let x and y be two positions, not necessarily in the same game. Let this be referred to as the outcome of a position. x and y are said to be **equivalent** if for any position z in any game, the combined positions x + z + y + z have the same outcome.  
Intuitively, this means that playing a game from position x, always has the same outcome as playing a game from position y. The outcome of a determined game is only dependent on its starting position. Thus fixed games G, with starting position x, and H, with starting position y, are equivalent if and only if x and y are equivalent.  
f














