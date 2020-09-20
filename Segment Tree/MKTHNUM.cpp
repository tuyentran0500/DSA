#include<bits/stdc++.h>
#define endl '\n'
#define maxN 100005
using namespace std;
struct Node{
    int val , left , right ;
} tree[20 * maxN];
int ver [maxN];
int n, peak = 0;
int a[ maxN] , b[maxN];
void update(int k , int ll , int rr , int pos){
    if (ll > pos || rr < pos || ll > rr) return ;
    tree[peak].val = tree[k].val +1 ;
    if (ll == rr) return ;
    int mid = (ll + rr) >> 1 , node = peak;
    tree[node].left = tree[k].left;   tree[node].right = tree[k].right;
    if (pos > mid){
        tree[node].right = ++peak;
        update(tree[k].right , mid+1 , rr , pos);
    }
    else {
        tree[node].left =++peak;
        update(tree[k].left , ll , mid , pos);
    }
}
int query (int p ,int q , int k){
    int ll = 1, rr = n , x = ver[p-1] , y = ver[q];
    while (ll < rr){
        int mid = (ll + rr) >> 1 , middle = tree [ tree[y].left ].val - tree[ tree[x].left ].val;
        if ( middle >= k){
            rr = mid;
            x= tree[x].left; y = tree[y].left;
 
        }
        else {
            k-= middle;
            ll = mid +1 ;
            x = tree[x].right ; y = tree[y].right;
        }
    }
    return ll;
}
int main(){
   // freopen ("f.txt","r" , stdin);
   // freopen ("f1.txt","w" , stdout);
    ios_base::sync_with_stdio(0);
    //memset( tree , 0 , sizeof tree);
    int q; cin >> n >> q;
    map<int,int> checker;
    for (int i=1;i<=n;++i)  { cin >> a[i] ; b[i] = a[i]; }
    sort ( b+1 , b+1+n);
    for (int i=1;i<=n;++i){
            checker[ b[i] ] = i;
            //cout << b[i] <<" " << checker[ b[i] ] << endl;
    }
    //cout << ver[0] << endl;
    for (int i=1;i<=n;++i){
        ver[i]= ++peak;
        update(ver[i-1], 1 , n , checker[ a[i] ]);
    }
   // for (int i=1;i<=peak;++i)  cout << tree[i].val <<" ";
    for (int i=0;i<q;++i){
        int u , v , k; cin >> u >> v >> k;
        cout << b[query(u, v, k)] << endl;
    }
}