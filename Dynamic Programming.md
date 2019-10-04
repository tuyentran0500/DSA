# Quy hoạch động.
Nguồn: Bài viết [VNOI](https://vnoi.info/wiki/algo/dp/Mot-so-ky-thuat-toi-uu-hoa-thuat-toan-Quy-Hoach-Dong)
Trong phần này, chúng ta sẽ đến với những bài toán QHĐ và các phương thức để giải quyết chúng. 
## 1. Đổi nhãn. 
Nhiều khi trong trạng thái QHĐ có 1 thành phần nào đấy với khoảng giá trị quá lớn, trong khi kết quả của hàm lại có khoảng giá trị nhỏ. Trong một vài trường hợp, ta có thể đảo nhãn để giảm số trạng thái. 
Một số bài tập ví dụ.
### Bài toán 1: [LCS](./LCS-advance.cpp)
Tìm xâu con chung của 2 xâu A[1...n], B[1...m].
#### Giới hạn.
n <= 5000.
m <= 10e6.
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
	+ F(i,j,value,k) = True --> F(i+1,j,value+a,k) = True;
	+ F(i,j,value,k) = True --> F(i,j+1,value+b,k) = True;
Do không cần quan tâm đến thứ tự của các phòng, mục tiêu của ta là xếp nhiều phòng nhất có thể, và mỗi phòng có tổng giá trị máy tính >= `v`. Do đó, khi value >= v, ta có thể chuyển từ phòng k sang phòng k + 1 và value mới = 0.
VD: `value + a >= v && F(i,j,value,k) = True --> F(i+1,j,0,k+1) = True`
Để rút gọn độ phức tạp thuật toán, ta đẩy (k, value) ra thành kết quả bài toán
[Source code](./computer_spoj.cpp).



