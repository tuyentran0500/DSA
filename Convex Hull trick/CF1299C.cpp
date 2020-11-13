/*input

*/
#include <bits/stdc++.h>
#define pr pair<ll,int>
#define ll long long
using namespace std;
const int N = 1000005;
// basic convex hull
// Find lower envelope.  
ll a[N];
int n;
vector<int> line;
double slope(int i,int j){	return 1.0 * (a[j] - a[i])/ (j - i); }
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	line.push_back(0);
	for(int i=1;i<=n;++i){
		while (line.size() >= 2){
			#define last (line.size() - 1)
			if (slope(line[last-1], line[last]) > slope(line[last-1], i)) line.pop_back();
			else break;
		}
		line.push_back(i);
	}
	line.push_back(n+1);
	// for(auto v : line) cerr << v << ' '; cerr << '\n';
	int pivot = 0;
	for(int i=1;i<=n;++i){
		if (line[pivot + 1] < i) pivot++;
		cout << fixed << setprecision(9) << slope(line[pivot], line[pivot+1]) << ' ';
	}
}