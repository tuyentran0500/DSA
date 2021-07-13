#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
using namespace std;
const int N  = 200005;
const ll INF = 1e15;
int n, q;
void chmax(ll& a, ll b){a = max(a, b); }
void chmin(ll& a, ll b){a = min(a, b); }
ll low = -INF, high = INF, add = 0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	up(i,1,n){
		ll A, T; cin >> A >> T;
		if (T == 1){
			low += A;
			high += A;
			add += A;
		}
		else if (T == 2){
			chmax(low, A);
			chmax(high, A);
		}
		else {
			chmin(low, A);
			chmin(high, A);
		}
	}

	cin >> q;
	up(i,1,q){
		ll X; cin >> X;
		cout << min(high, max(low, X + add)) << '\n';
	}
}