/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) (((x) >> (i)) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define ll long long
#define int ll
using namespace std;
const int N = 100005;
const int K = 11;
ll a[N], dp[N][K], s1[N], s2[N];
// s1[i] = sigma(i*a[i])
// s2[i] = sigma(a[i]);
int n,k;
vector< pr > line[K];
int cur[N];
bool bad(pr l1, pr l2, pr l3){
	// reverse order I guess.  
	return (l1.first - l3.first)*(l1.second - l2.second) > (l1.first - l2.first) * (l1.second - l3.second);
}
void add(int a,int b, int idx){
	pr u = {a, b};
	while (line[idx].size() > 1){
		#define last line[idx].size() - 1
		if (bad(line[idx][last-1], line[idx][last], u)) line[idx].pop_back();
		else break;
	}
	line[idx].push_back(u);
}
int f(int x, pr u) { return u.first * x + u.second; }
int query(int x, int idx){
	int sz = line[idx].size();
	int& cnt = cur[idx];
	if (cnt >= sz) cnt = sz - 1;
	while (true){
		if (cnt < sz - 1 && f(x, line[idx][cnt+1]) < f(x, line[idx][cnt])) cnt++;
		else break;
	}
	return f(x, line[idx][cnt]);
}
int get(int l,int r){
	return s1[l] - l * s2[l] + s2[r+1]*l - s1[r+1];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n) cin >> a[i];
	down(i,n,1) {
		s1[i] = s1[i+1] + a[i] * i;
		s2[i] = s2[i+1] + a[i];
	}
	// dp[i][k] = s1[i] - i*s2[i] + s2[j] * i + (dp[j][k-1] - s1[j]);
	//                                A     x        B  
	up(i,0,k) line[i].push_back({0, 0});
	down(i,n,1){
		for(int step=1;step <= k;++step) {
			dp[i][step] = query(i, step - 1) + s1[i] - i*s2[i];
		}
		for(int step=1;step <= k;++step){
			add(s2[i], dp[i][step] - s1[i], step);			
		}
	}
	cout << dp[1][k];
}