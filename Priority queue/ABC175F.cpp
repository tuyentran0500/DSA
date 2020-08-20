/*input
2
cccbca 5
acb 1
*/
// https://atcoder.jp/contests/abc175/tasks/abc175_f
// Clean code.
#include <bits/stdc++.h>
#define ps pair<string,int>
#define ll long long
using namespace std;
const int N = 55;

string a[N];
ll c[N];
int n;
map< ps, ll > d;
struct query {
	ps state;
	ll val;
	query(){state = {"", -1}; val = 0; }
	query(ps _state, ll _val) {state = _state; val = _val;}
};
bool operator>(query a, query b){
	return a.val > b.val;
}
pair<string,int> compose(string left, string right){
	int pos_l = left.size() - 1, pos_r = 0;
	while (pos_l >=0 && pos_r < (int)right.size()){
		if (left[pos_l] != right[pos_r]) return {"", -1}; // cannot compose.  
		pos_l--;
		pos_r++;
	}
	string res = "";
	if (pos_l < 0){
		for(int i=pos_r;i<right.size();++i) res += right[i];
		return {res, 1};
	}
	if (pos_r == right.size()){
		for(int i=0;i<=pos_l;++i) res += left[i];
		return {res, 0};
	}
}
bool is_palindrome(string s){
	if (s.size() <= 1) return true;
	int n = s.size();
	for(int i=0;i<n;++i){
		if (s[i] != s[n-1-i]) return false;
	}
	return true;
}
long long solve(){
	priority_queue< query, vector<query>, greater<query> > pq;
	for(int i=1;i<=n;++i){
		ps curNode = {a[i],1};
		if (d[curNode]) d[curNode] = min(d[curNode], c[i]);
		else d[curNode] = c[i];
		pq.push(query(curNode, 1LL * c[i]));
	}
	while (pq.size()){
		ps u = pq.top().state;
		ll curVal = pq.top().val;	pq.pop();
		if (curVal != d[u]) continue;
		if (is_palindrome(u.first)) return curVal;
		for(int i=1;i<=n;++i){
			string left = a[i], right = u.first;
			if (!u.second) swap(left, right);
			ps v = compose(left, right);
			if (v.second == -1) continue;
			if (!d[v] || d[v] > curVal + c[i]){
				pq.push(query(v, curVal + c[i]));
				d[v] = curVal + c[i];
			}
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> c[i];
	}
	cout << solve();
	return 0;
}