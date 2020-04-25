## Xác xuất và ứng dụng.
 
### Giá trị kì vọng(Expected Value):
- Biến ngẫu nhiên(Random Variable) là 1 biến mà giá trị của nó là kết quả của 1 lần thí nghiệm.
- Giá trị kì vọng: Với X là 1 random variable, E(x) là giá trị trung bình của X, nếu ta thực hiện thí nghiệm vô số lần.

### Linearity of Expectation
- Linearity of Expectation là 1 kĩ năng quan trọng nhất khi làm các bài về Expxpected value.
**VD:** Tính Expected value của 2 lần tung xúc xắc riêng biệt.
Xét riêng từng xúc xắc:
	+ Đặt E(X1) là expected value của giá trị xúc xắc 1.
	+ Đặt E(x2) là expected value của giá trị xúc xắc 2.
E(X1) = E(X2) = (1/6) * 1 + (1/6) * 2 + ... + (1/6) * 6 = 3.5.
Linearity of Expectation cho ta công thức sau:
E(X1 + X2) = E(X1) + E(X2) = 7
Phát biểu đầy đủ:
- Nếu X1, X2, ... Xk là các random variable có cùng không gian mẫu:
E(X1 * a1 + X2 * a2 + ... Xn * an) = a1 * E(X1) + a2 * E(X2) + ... + an * E(Xn).
Note: Các biến không cần phải độc lập.
