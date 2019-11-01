#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
// Số test kiểm tra
const int NTEST = 50;
string convert(int n,int maxTest){
	string ans = "";
	while (n){
        char c = '0' + (n%10);
		ans = (char)(n % 10 + '0') + ans;
		n/=10;
	}
	while (ans.size() < maxTest) ans = "0" + ans;
	return ans;
}
int main(){
    srand(time(NULL));
    system("rmdir /s Test");
    system("mkdir Test");
    system("mkdir input");
    system("mkdir output");
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
    	// run solve and gen.
        system("gen.exe");
        system("solve.exe");
        // Nếu dùng linux thì thay fc bằng diff
        string inp = "input" + convert(iTest,2) + ".txt";
        system(("rename solve.inp " + inp).c_str());
        system(("move " + inp + " input").c_str());
        string out = "output" + convert(iTest,2) + ".txt";
        system(("rename solve.OUT " + out).c_str());
        system(("move " + out + " output").c_str());
    }
    system("move input Test");
    system("move output Test");
    return 0;
}