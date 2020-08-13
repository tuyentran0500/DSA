/*input

*/
// https://community.topcoder.com/stat?c=problem_statement&pm=15869&rd=17773
#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
#define mid ((l+r)/2)
#define pr pair<int,int>
using namespace std; 
struct LandSplitter{
	long long cheapest(int N,int A,int B){
		long long ans = -1;
		if (B == A) {
			if (N % B) return -1;
			int cnt = N/B;
			return 1LL * cnt * (cnt-1)/2 * B * B;
		}
		for (int i=1;i<=sqrt(N);++i){
			int div = N/i;
			if (1LL * div * A <= N && 1LL * div * B >= N) {
				int Bgroup = min(div, (N - div * A)/(B - A));
				int Agroup = div - Bgroup;
				int lastDiff = 0;
				if (Agroup) {
					lastDiff = (N - Bgroup * B - Agroup * A) + A;
					Agroup--;
				}
				ans = max(ans, 1LL * Bgroup * B * B + 1LL * Agroup * A * A + 1LL * lastDiff * lastDiff);
			}
			if (1LL * i * A <= N && 1LL * i * B >= N){
				int Bgroup = min(i, (N - i * A)/(B - A));
				int Agroup = i - Bgroup;
				int lastDiff = 0;
				if (Agroup) {
					lastDiff = (N - Bgroup * B - Agroup * A) + A;
					Agroup--;
				}
				ans = max(ans, 1LL * Bgroup * B * B + 1LL * Agroup * A * A + 1LL * lastDiff * lastDiff);
			}
		}
		if (ans == -1) return -1;
		return (1LL * N * N - ans)/2LL;
	}
};

#ifdef MAIN
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	LandSplitter solve;
	cout << solve.cheapest(12,3,3) << '\n';
	cout << solve.cheapest(12,3,4) << '\n';
	cout << solve.cheapest(47,1,47) << '\n';
	cout << solve.cheapest(70,40,50) << '\n';
	cout << solve.cheapest(47,4,7);

}
#endif 