#include <bits/stdc++.h>
#define pr pair<int,int>
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 55;
const int logN = 30;
const long long mod = 1000000007;
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
	matrix(vector< vector<long long> > altMat){
		int n = altMat.size();
		int m = altMat[0].size();
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
long long c[N][N];
int n,k;
void init(){
	c[0][0] = 1;
	for(int i=1;i<N;++i){
		c[0][i] = c[i][i] = 1;
		for(int j=1;j<i;++j) c[j][i] = (c[j][i-1] + c[j-1][i-1]) % mod;
	}	
	// cout << c[5][10] << '\n';


}
void solve(){
	vector< vector<long long> > cur(k+2, vector<long long>(1, 1));
	matrix ans = matrix(cur);
	// ans.print();
	cur.assign(k+2, vector<long long> (k+2, 0));
	cur[0][0] = 1;
	for(int i=1;i<=k+1;++i) cur[0][i] = c[i-1][k];
	for(int i=1;i<=k+1;++i){
		for(int j=1;j<=i;++j){
			cur[i][j] = c[j-1][i-1];
		}
	}
	matrix sub = matrix(cur);
	// sub.print();
	sub = power(sub, n-1);
	// sub.print();
	ans = sub * ans;
	// ans.print();
	cout << ans.mat[0][0] << '\n';
}
int main(){
	//freopen("solve.inp","r", stdin);
	init();
	while (cin >> n >> k){
		solve();
	}
}