/*input

*/
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std;
const int N = 1000015; 
const int ALPHABET = 256;
int p[N], c[N];
string s;
int lenS[10];
int numS;
int n;
void sArray(string s){
	vector<int> c(n), cnt(max(n, ALPHABET), 0);
	for(int i=0;i<n;++i) cnt[s[i]]++;
	for(int i=1;i<ALPHABET;++i) cnt[i] += cnt[i-1];
	for(int i=0;i<n;++i) p[--cnt[s[i]]]

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
}