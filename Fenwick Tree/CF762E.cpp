/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define POS(x) (upper_bound(a.begin(), a.end(), x) - a.begin())
using namespace std;
const int N = 100005;
int pos[N], r[N], f[N];
vector<int> freq[10010];
bool compareLeft(int u,int v){
	return pos[u] < pos[v];
}
bool compareRight(int u,int v){
	return pos[u] - r[u] < pos[v] - r[v];
}
// BIT template
int b[N];
int n,k;

void upd(int u,int val){
	while (u <= n){
		b[u] += val;
		u += (u & -u);
	}
}
int get(int u){
	int ans = 0;
	while (u){
		ans += b[u];
		u -= (u & -u);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	up(i,1,n){
		cin >> pos[i] >> r[i] >> f[i];
		freq[f[i]].push_back(i);
	}
	// compress position
	vector<int> a;
	up(i,1,n) a.push_back(pos[i]);
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	long long ans = 0;
	for(int i=1;i<=10000;++i){
		vector<int> left, right;
		for(auto v : freq[i]) left.push_back(v);
		for(int j=max(0, i-k);j<=i+k;++j)
			for(auto v : freq[j]) right.push_back(v);
		sort(left.begin(), left.end(), compareLeft);
		sort(right.begin(), right.end(), compareRight);
		int posR = 0; 
		for(auto u : left){
			while (posR < right.size()){
				int v = right[posR];
				if (pos[v] - r[v] > pos[u]) break;
				upd(POS(pos[v]), 1);
				posR++;
			}
			ans += get(POS(pos[u] + r[u])) - get(POS(pos[u] - 1)) - 1;
		}
		while (posR < right.size()) upd(POS(pos[right[posR++]]), 1);
		for(auto v : right) upd(POS(pos[v]), -1);
	}
	cout << ans;
	// cout << POS(3) << '\n';
}