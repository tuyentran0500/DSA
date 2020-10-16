	/*input
	 
	*/
	#include <bits/stdc++.h>
	#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
	#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
	#define bits(x,i) ((x >> i) & 1)
	#define mid ((l+r)/2)
	#define pr pair<int,int>
	using namespace std;
	const int N = 200005;
	#define int long long
	int n,k;
	int pos[N], a[N];
	long long absSum(int l,int r){
		if (l >= 0) return 1LL*(l + r)*(r- l + 1)/2;
		if (r <= 0) return absSum(-r,-l);
		return absSum(l, 0) + absSum(0, r);
	}
	signed main(){
		ios_base::sync_with_stdio(0); cin.tie(0);
		cin >> n >> k;
		up(i,1,n){
			string s; cin >> s;
			if (s[0] != '?') a[i] = stoi(s);
			else a[i] = INT_MAX;
		}
		long long ans = 0;
		a[0] = INT_MIN;
		up(i,n+1,n+1+k) a[i] = INT_MAX;
		up(i,1,n+k){
			if (a[i] != INT_MAX || i > n){
				ans += abs(a[i]);
				int pre = pos[i % k];
				int x = (i - pre)/k - 1;
				if (pre == 0) x = i/k + (i % k != 0) - 1;
				// cout << i << ' ' << pre << ' ' << x << '\n';
				if (a[i] - x <= a[pre]) {
					cout << "Incorrect sequence\n";
					return 0;
				}
				long long cur = absSum(a[pre]+1, a[pre]+x);
				cur = min(cur, absSum(a[i]-x, a[i]-1));
				if ((a[pre] < -(x-1)/2 && a[i] > x/2) || (a[pre] < -x/2 && a[i] > (x-1)/2)) 
					cur = min(cur, absSum(-(x-1)/2, x/2));
				ans += cur;
				if (cur == absSum(a[pre]+1, a[pre]+x)){
					up(j,1,x) a[i - (x - j + 1) * k] = a[pre] + j;
				}
				else if (cur == absSum(a[i]-x, a[i]-1)){
					up(j,1,x) a[i - (x - j + 1) * k] = a[i] - (x - j + 1);
				}
				else {
					if (a[i] > x/2) up(j,1,x) a[i - (x - j + 1) * k] = x/2 - (x - j);
					else up(j,1,x) a[i - (x - j + 1) * k] = (x-1)/2 - (x - j);  
				}
				// cout << i << ' ' << cur << ' ' << x << '\n';
				pos[i % k] = i;
			}
		}
		// cout << ans << '\n';
		up(i,1,n) cout << a[i] <<  ' ';
	}