/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N  = 100005;
#define pr pair<int,int>
int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    vector<int> upwardFishes;
    for(int i=0;i<A.size();++i){
        if (B[i] == 0){
            while (upwardFishes.size() && A[upwardFishes.back()] < A[i]) {
              upwardFishes.pop_back();
            }
        }
    }
}
int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> a; 
    cin >> n;
    for(int i=0;i<n;++i){
        int v; cin >> v;
        a.push_back(v);
    }
    cout << solution(a);
}