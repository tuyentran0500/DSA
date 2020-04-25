#include <iostream>
using namespace std;
const int N = 505;
long long sum[N][N];
int q;
int n,m;
long long getSum(int x1,int y1, int x2, int y2){
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}
int main(){
    // freopen("solve.inp","r", stdin);
    // freopen("solve.out","w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> sum[i][j];
            sum[i][j] += 1LL*(sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
        }
    }
    cin >> q;
    while (q--){
        int x,y,l; cin >> x >> y >> l;
        cout << getSum(x,y,x+l-1,y+l-1) << '\n';
    }
}