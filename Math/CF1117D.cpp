/*input

*/
// https://codeforces.com/contest/1117/problem/D
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
#define int long long
using namespace std;
const int N = 105;
const int logN = 60;
const int mod = 1e9 + 7;
struct matrix{
	vector< vector<long long> > mat;
	pr matsize;
	matrix(){ matsize = {0,0}; }
	matrix(int n){
		matsize = {n, n};
		mat.assign(n, vector<long long> (n, 0LL));
		for(int i=0;i<n;++i) mat[i][i] = 1;
	}
	matrix(int n,int m){
		matsize = {n, m};
		mat.assign(n, vector<long long>(m, 0LL));
	}
	matrix(vector< vector<long long> > altMat,int n,int m){
		mat = altMat;
		matsize = {n, m};
	}
	void print(){
		for(int i=0;i<matsize.first;++i){
			for(int j=0;j<matsize.second;++j){
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
};
matrix operator*(matrix a,matrix b){
	int n = a.matsize.first, m = a.matsize.second, p = b.matsize.second;
	matrix ans = matrix(n, p);
	for(int i=0;i<n;++i){
		for(int j=0;j<p;++j){
			for(int k=0;k<m;++k) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}
matrix power(matrix a,long long n){
	matrix ans = matrix(a.matsize.first);
	for(int i=0;i<logN;++i){
		if (bits(n, i)) ans = ans * a;
		a = a * a;
	}
	return ans;
}
long long n;
int m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vector< vector<long long> > f;
	f.assign(1, vector<long long>(m, 1));
	matrix F = matrix(f,1,m);
	// F.print();
	// 
	vector< vector<long long> > ker; 
	ker.assign(m, vector<long long> (m, 0));
	ker[0][0] = ker[m-1][0] = 1;
	for(int i=1;i<m;++i) ker[i-1][i] = 1;
	matrix baseMat = matrix(ker, m, m);
	// baseMat.print();

	// baseMat = baseMat * baseMat;
	// baseMat.print();
	F = F * power(baseMat, n);
	cout << F.mat[0][m-1];
}