/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
#define pos(i,j) ((i - 1) * m + j - 1)
vector<int> dp, a, maxL, maxR;
int n,m;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.assign(n*m, 0);
    dp.assign(n*m, -1e9);
    maxL.assign(n*m, 0);
    maxR.assign(n*m, 0);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin >> a[pos(i,j)];
    }
    for(int i=n;i>=1;--i){
        maxR[pos(i,m)] = a[pos(i,m)];
        for(int j=m-1;j>=1;--j){
            maxR[pos(i,j)] = max(0LL, maxR[pos(i,j+1)]) + a[pos(i,j)];
        }
    }
    for(int i=1;i<=n;++i){
        maxL[pos(i,1)] = a[pos(i, 1)];
        for(int j=2;j<=m;++j){
            maxL[pos(i,j)] = max(0LL, maxL[pos(i,j-1)]) + a[pos(i,j)];
        }
    }
    for(int j=1;j<=m;++j){
        dp[pos(1,j)] = maxR[pos(1,j)];
        if (j > 1) dp[pos(1,j)] += max(0LL, maxL[pos(1,j-1)]);
    } 
 
    for(int i=2;i<=n;++i){
        int s = 0, mx = -1e9;
        for(int j=1;j<=m;++j){
        	int add = dp[pos(i-1, j)] - s;
        	if (j > 1) add += max(0LL, maxL[pos(i, j-1)]);
            mx = max(mx, add);
            dp[pos(i,j)] = max(dp[pos(i,j)], s + maxR[pos(i,j)] + mx);
            s += a[pos(i,j)];
        }
        s = 0, mx = -1e9;
        for(int j=m;j>=1;--j){
        	int add = dp[pos(i-1,j)] - s;
        	if (j < m) add += max(0LL, maxR[pos(i,j+1)]);
            mx = max(mx, add);
            dp[pos(i,j)] = max(dp[pos(i,j)], s + maxL[pos(i,j)] + mx);
            s += a[pos(i,j)];
        }
    }
    int ans = -1e9;
    up(j,1,m) ans = max(ans, dp[pos(n,j)]);
    cout << ans;
}