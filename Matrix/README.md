# Matrix template  
```
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
```