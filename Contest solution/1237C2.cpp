#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define xyz_point pair<int,pair<int,int>
#define xy_point pair<int,int>
using namespace std;
struct point{
	int x,y,z;
	point(){x = y = z = 0;};
	point(int _x,int _y,int _z){x = (_x); y = (_y); z = (_z);}
};
const int N = 50001;
point p[N];
int n;
vector< pair<int,int> > ans;
bool compare1D(int a,int b){
	return (p[a].z < p[b].z);
}
bool compare2D(int a,int b){
	return (p[a].y < p[b].y);
}
bool compare3D(int a,int b){
	return (p[a].x < p[b].x);
}
int solve1D(vector<int> v){
	sort(v.begin(), v.end(), compare1D);
	for(int i=0;i+1 < v.size(); i+=2) ans.push_back(pair<int,int>(v[i], v[i+1]));
	return ((v.size() & 1) ? v.back() : 0);
}
int solve2D(vector<int> v){
	sort(v.begin(), v.end(), compare2D);
	vector<int> temp, res;
	temp.push_back(v.front());
	for(int i=1;i<v.size();++i){
		if (p[v[i]].y == p[temp[0]].y) temp.push_back(v[i]);
		else {
			int cur = solve1D(temp);
			if (cur) res.push_back(cur);
			temp.clear();
			temp.push_back(v[i]);
		}
	}
	if (temp.size()) {
		int cur = solve1D(temp);
		if (cur) res.push_back(cur);
	}
	sort(res.begin(), res.end(), compare2D);
	for(int i=0;i+1<res.size();i+=2) ans.push_back(pair<int,int>(res[i], res[i+1]));
	return ((res.size() & 1) ? res.back() : 0);
}

void solve3D(vector<int> v){
	sort(v.begin(), v.end(), compare3D);
	vector<int> temp, res;
	temp.push_back(v.front());
	for(int i=1;i<v.size();++i){
		if (p[v[i]].x == p[temp[0]].x) temp.push_back(v[i]);
		else {
			int cur = solve2D(temp);
			if (cur) res.push_back(cur);
			temp.clear();
			temp.push_back(v[i]);
		}
	}
	if (temp.size()) {
		int cur = solve2D(temp);
		if (cur) res.push_back(cur);
	}
	sort(res.begin(), res.end(), compare3D);
	for(int i=0;i+1<res.size();i+=2) ans.push_back(pair<int,int>(res[i], res[i+1]));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int> v;
	up(i,1,n) {
		int x,y,z; cin >> x >> y >> z;
		p[i] = point(x,y,z);
		v.push_back(i);
	}
	solve3D(v);
	for(int i=0;i<ans.size();++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
}