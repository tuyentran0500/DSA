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
const int N  = 200005;
int n;
int f[N];
int cnt[N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i*i<=n;++i){
        for(int j=i*i;j<=n;j += i*i) f[j] = max(f[j], i * i);
    }
    up(i,1,n) cnt[i / f[i]]++;
    long long ans = 0;
    up(i,1,n) ans += 1LL * cnt[i] * cnt[i];
    cout << ans;
} 