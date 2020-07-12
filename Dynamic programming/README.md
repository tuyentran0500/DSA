# Quy hoạch động.
Nguồn: Bài viết [VNOI](https://vnoi.info/wiki/algo/dp/Mot-so-ky-thuat-toi-uu-hoa-thuat-toan-Quy-Hoach-Dong).

Trong phần này, chúng ta sẽ đến với những bài toán QHĐ và các phương thức để giải quyết chúng. 
## 1. Đổi nhãn. 
Nhiều khi trong trạng thái QHĐ có 1 thành phần nào đấy với khoảng giá trị quá lớn, trong khi kết quả của hàm lại có khoảng giá trị nhỏ. Trong một vài trường hợp, ta có thể đảo nhãn để giảm số trạng thái. 

Một số bài tập ví dụ.
### Bài toán 1: [LCS](./LCS-advance.cpp)
Tìm xâu con chung của 2 xâu A[1...n], B[1...m].
#### Giới hạn.
- n <= 5000.
- m <= 10e6.  
Các kí tự trong xâu là 'A'...'Z'.
#### Lời giải.
**Thuật toán kinh điển:**  
Gọi F(i,j) = k là độ dài dãy con chung lớn nhất của xâu A[1..i] và B[1..j]. 
Từ đó ta có công thức LCS kinh điển F(i,j) = max ( F(i-1,j), F(i,j-1), if (A[i] == B[j]) F(i-1,j-1) + 1)  
Tuy nhiên, có thể thấy rằng, m có giới hạn lớn, do đó ta cần đẩy biến j ra bên ngoài, từ đó ta thay được 1 hàm quy hoạch động mới.  
**Thuật toán chuẩn:**  
Gọi F(i,k) = j là vị trí j nhỏ nhất sao cho LCS(A[1...i], B[1...j]) = k.
Tạo mảng nextPos[i,c] = j nhỏ nhất > i sao cho a[j] = c.  
Dễ thấy F(i+1,k+1) = next(j, a[i+1]).  
Ngoài ra, ta cũng cần cập nhật F(i+1,j) theo F(i,j).  
### Bài toán 2: [Computer SPOJ](https://vn.spoj.com/problems/COMPUTER/).
#### Đề bài: 
Công ty XYZ quyết định mua x máy tính bàn với giá a đồng mỗi cái, y máy tính laptop với giá b đồng mỗi cái.

Có n phòng, phòng thứ i sẽ được mốt số máy tính với tổng giá trị cost[i].
Biết rằng cost[i] <= cost[j] với i <= j.

Tìm cách chia máy tính sao cho phòng nhỏ nhất có tổng giá trị lớn nhất.
#### Lời giải:
Từ cụm "Tìm giá trị phòng nhỏ nhất lớn nhất", ta có thể suy ra cần phải chặt nhị phân tổng giá trị nhỏ nhất `v` để giải quyết bài toán.

Nhận xét: Do ta chỉ cần quan tâm phần tử nhỏ nhất, do đó thứ tự ưu tiên của phòng không quan trọng.

Gọi hàm `F(i,j,value,k) = true` nếu có thể phân bố i máy tình bàn và j laptop, cho phòng hiện tại k có tổng giá trị là value. Ta có thể chuyển trạng thái trong O(1) như sau: 
- F(i,j,value,k) = True --> F(i+1,j,value+a,k) = True;
- F(i,j,value,k) = True --> F(i,j+1,value+b,k) = True;

Do không cần quan tâm đến thứ tự của các phòng, mục tiêu của ta là xếp nhiều phòng nhất có thể, và mỗi phòng có tổng giá trị máy tính >= `v`. Do đó, khi value >= v, ta có thể chuyển từ phòng k sang phòng k + 1 và value mới = 0.

VD: `value + a >= v && F(i,j,value,k) = True --> F(i+1,j,0,k+1) = True`
Để rút gọn độ phức tạp thuật toán, ta đẩy (k, value) ra thành kết quả bài toán

[Source code](./computer_spoj.cpp).

## 2. Chia để trị.
### Bài toán 1: [2 nhà máy CEOI](https://www.oi.edu.pl/old/ceoi2004/)
#### Đề bài:
Có n cây cổ thụ được trồng trên 1 con đường từ đỉnh đồi đến chân đồi. Chính phủ địa phương quyết định cắt bỏ chúng.

Cây chỉ có thể vận chuyển theo 1 chiều duy nhất: hướng về chân đồi.
Có 1 nhà máy cưa ở cuối con đường. Hai nhà máy mới có thể được xây thêm ở con đường. Hãy xác định vị trí tối ưu để xây chúng, để cực tiểu hóa chi phí vận chuyển, biết chi phí vận chuyển là 1kg gỗ đi 1 met là 1 cent.

Giới hạn:
- n số cây <= 20000.
- n dòng sau đó gồm 2 chỉ số Wi, Di - Wi là khối lượng của cây, Di là khoảng cách giữa cây đó và cây thứ i+1.
- Dữ liệu đảm bảo tính toán không quá 2 * 10^9. 
#### Lời giải:
Đầu tiên, ta nhận thấy rằng, với việc biết được vị trí của 2 hàm đặt máy cưa, ta có thể tính toán công thức trong O(1).

Nhờ đó, ta so sánh được mọi cách đặt với độ phức tạp O(N^2).

Ta sẽ tập trung vào phần tối ưu thuật toán:

Gọi best(i) = j là vị trí đặt máy cưa tốt nhất nếu ta đặt 1 máy cưa ở vị trí i.
Dễ thấy rằng: best(i) <= best(i+1).  
Do đó hàm quy hoạch động có tính tịnh tiến, do đó ta có thể chia để trị dựa trên ý tưởng của cây IT.  
Với i < j, best(i) < best(j).  
Nên nếu ta tìm kiếm best(j) trong khoảng (from, to).\
Thì ta chỉ cần tìm kiếm best(i) trong khoảng (from , best(j)).
```
void solve(int l,int r,int from,int to){
	if (l > r) return;
	int mid = (l+r) >> 1;
	best[mid] = from;
	up(i,from+1, to){
		if (eval(mid + 1, best[mid]) > eval(mid + 1, i))	best[mid] = i;
	}
	solve(l,mid-1, from, best[mid]);
	solve(mid+1,r, best[mid], to);
}
```
Lưu ý: hàm eval dùng để tính chi phí vận chuyển nếu biết vị trí của 2 cây.
[Source code](./two_sawmills.cpp)
### Bài toán 2: [SEQOART - Hackerrank](https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem)
#### 1. Đề bài:
Cho dãy L số C[1..L] cần chia dãy này thành G đoạn liên tiếp. Với đoạn thứ i bắt đầu từ L-->R, ta gọi chi phí cắt của đoạn là cost(i) = sum(C[L-->R]) * (R - L + 1).\
Hãy xác định cách phân hoạch để chi phí là nhỏ nhất. \
Giới hạn:
- 1 <= L <= 8000.
- 1 <= G <= 800.
- 1 <= C[i] <= 10^9.
#### 2. Lời giải:
Gọi dp[i,j] là chi phí nhỏ nhất chia đoạn 1-->i thành j đoạn.  
dp[i,j] = min(dp(k, j-1) + Cost(k,i))  
Với cost(k,i) là chi phí để cắt đoạn từ k --> i.  
Từ đó, ta có thuật O(L^2 * G).  
Có thể thấy được rằng tập trung vào tối ưu phần tìm min, khi đó thuật toán sẽ là O(G.L.Log(L)).  
Ta cũng có nhận xét tương tự rằng: dp(i,j) <= dp(i+1,j).  
Áp dụng tương tự bài toán 1, ta tìm được giá trị của hàm.  
[Source code](./SEQPART.cpp).
## 3. Tối ưu bằng STACK.
### Bài toán 1: [BLOCK-IZHO 2014](https://oj.uz/problem/view/IZhO14_blocks)
#### 1. Đề bài:
Cho dãy n số a[1],a[2],...a[N]. Xét cách chia dãy số a thành K nhóm, mỗi nhóm chứa một đoạn liên tiếp các phần tử của a. Gọi trọng số của 1 cách chia là tổng các phần tử lớn nhất của mỗi nhóm.  
Tìm cách chia dãy số thành K nhóm sao cho trọng số cách chia là nhỏ nhất.  
Giới hạn:
- 1 <= N <= 100000.
- 1 <= K <= 100.
- a[i] <= 1000000.
#### Lời giải:
Gọi F(i,j) là tổng trọng số bé nhất nếu chia i phần tử đầu tiên của dãy, thành j đoạn. 
Ta có công thức: F(i,j) = min(F(i',j-1) * max(a[i'+1], ....a[i]))  
Gọi L[i] là vị trí xa nhất mà max(a[j]) với j = L[i],...,i.  
Ta có 2 TH:
- a[i] là không là trọng số của dãy thứ j. Khi đó F(i,j) = F(L[i],j).
- a[i] là trọng số của dãy thứ j. Khi đó F(i,j) = max(F(i',j-1)) với i' = (L[i], i).  

Để tối ưu công thức trong trường hợp 2, ta hoàn toàn có thể cập nhật công thức trong O(logn). Tuy nhiên, ta có thể dùng stack để duy trì giá trị min trong đoạn (L[i], i).  

- Blog: [Non trivial DP tricks and techniques](https://codeforces.com/blog/entry/47764)  













