/*input
2
4
1 2 3 4
8
5 4 3 2 1 9 10 15
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define int unsigned long long
using namespace std;
const int N = 20001;
int x,t,n;
priority_queue<int, vector<int> ,greater<int> > pq;
main(){
	ios_base::sync_with_stdio(false);
	cin>>t;
	while (t--){
		cin>>n; 
		for(int i=1;i<=n;++i){
			cin>>x; pq.push(x);
		} 
		int res = 0;
		while (pq.size() >= 2){
			int v = pq.top(); pq.pop();
			int u = pq.top(); pq.pop(); 
			pq.push(u+v);
			res+=u+v;
		}
		if(pq.size()) pq.pop(); 
		cout<<res<<'\n';
	}
} 