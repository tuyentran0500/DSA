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
int solution(vector<int> &A) {
    // Implement your solution here
    vector<pr> disc;
    for(int i=0;i<A.size();++i){
        disc.push_back({i - A[i], i + A[i]});
    }
    sort(disc.begin(), disc.end());
    int ans = 0;
    for(int i=0;i<disc.size();++i){
        int j = upper_bound(disc.begin(), disc.end(), pr{disc[i].second, 0}) - disc.begin();
        ans += (j - i);
        if (ans > 10000000) return -1;
    }
    return ans;
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