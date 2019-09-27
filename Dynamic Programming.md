# Quy hoạch động.
Nguồn: Bài viết [VNOI](https://vnoi.info/wiki/algo/dp/Mot-so-ky-thuat-toi-uu-hoa-thuat-toan-Quy-Hoach-Dong)
Trong phần này, chúng ta sẽ đến với những bài toán QHĐ và các phương thức để giải quyết chúng. 
## 1. Đổi nhãn. 
Nhiều khi trong trạng thái QHĐ có 1 thành phần nào đấy với khoảng giá trị quá lớn, trong khi kết quả của hàm lại có khoảng giá trị nhỏ. Trong một vài trường hợp, ta có thể đảo nhãn để giảm số trạng thái. 
Một số bài tập ví dụ.
### **LCS**
Tìm xâu con chung của 2 xâu A[1...n], B[1...m].
#### Giới hạn.
n <= 5000.
m <= 10e6.
Các kí tự trong xâu là 'A'...'Z'.
#### Lời giải.
**Thuật toán kinh điển:**
- Gọi F(i,j) = k là độ dài dãy con chung lớn nhất của xâu A[1..i] và B[1..j]. 
Từ đó ta có công thức LCS kinh điển F(i,j) = max ( F(i-1,j), F(i,j-1), if (A[i] == B[j]) F(i-1,j-1) + 1)
Tuy nhiên, có thể thấy rằng, m có giới hạn lớn, do đó ta cần đẩy biến j ra bên ngoài, từ đó ta thay được 1 hàm quy hoạch động mới.
*** Thuật toán chuẩn **  
Gọi F(i,k) = j là vị trí j nhỏ nhất sao cho LCS(A[1...i], B[1...j]) = k.
Tạo mảng nextPos[i,c] = j nhỏ nhất > i sao cho a[j] = c.
Dễ thấy F(i+1,k+1) = next(j, a[i+1]).
Ngoài ra, ta cũng cần cập nhật F(i+1,j) theo F(i,j).
### [Computer SPOJ](https://vn.spoj.com/problems/COMPUTER/).




