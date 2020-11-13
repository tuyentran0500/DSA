# Kĩ thuật bao lồi.  
Nguồn: http://vnoi.info/wiki/translate/wcipeg/Convex-Hull-Trick  
## Template  
```
long double slope(pr l1, pr l2){return 1.0 * (l1.first - l2.first)/(l1.second - l2.second);}
bool bad(pr l1, pr l2, pr l3){ return slope(l1, l3) < slope(l1, l2); }
vector<pr> line;
#define sz line.size()
void add(pr u){
	while (sz > 1){
		if (bad(line[sz-2], line[sz-1], u)) line.pop_back();
		else break;
	}
	line.push_back(u);
}
int f(int x, pr u){return x * u.first + u.second; }
int query(int x){ // two pointers.  
	static int cur = 0;
	if (cur >= sz) cur = sz-1;
	while (cur + 1 < sz && f(x, line[cur]) < f(x, line[cur+1])) cur++;
	return f(x, line[cur]);
}  
```
Binary search for the query  
```
int query(int x){ // binary search on query.  
	if (!sz) return 0;
	int ans = f(x, line[0]);
	int l = 1, r = sz - 1;
	while (l <= r){
		int val1 = f(x, line[mid-1]), val2 = f(x, line[mid]);
		if (val1 > val2){ // really ??
			l = mid + 1;
		}
		else r = mid - 1;
		ans = min(ans, min(val1, val2));
	}
	return ans;
}
```  
## Bài toán cơ bản  
> Cho một tập lớn các đường thẳng có dạng $y = m_i * x + b_i$ và 1 số lượng truy vất. Mỗi truy vấn là 1 số x và hỏi giá trị cực tiểu y có thể đạt được nếu chúng ta có thế x vào 1 trong số những phương trình đã cho.  

Bài toán này ta hoàn toàn có thể giải bằng bao lồi.  

## [WATER BALANCE]( https://codeforces.com/problemset/problem/1299/C)   
> Cho dãy $a_1, a_2,... a_n$.
Bạn có thể thực hiện vô hạn thao tác [l, r] bằng các thay toàn bộ các phần tử $a_l, .... a_r$ bằng = $\frac{a_l + a_{l+1} + ... + a_r}{r - l + 1}$.  
Hỏi dãy nhỏ nhất mà bạn đạt được là gì.  
Giới hạn: $n \leq 10^6$  

Biến đổi bài toán:  
Đặt pref[i] = $\sum_{j = 1}^{j = i} a[i]$  
Khi đó bạn có phép biến rồi thao tác [l, r] thành: $\frac{pref[r] - pref[l-1]}(r - (l - 1))$.    
Ta nhận thấy công thức trên có dạng $\frac{y_1 - y_2}{x_1 - x_2}$. Đây chính là hệ số góc của đường thẳng được tạo bởi 2 điểm (x1, y1) và (y1, y2).  
Bài toán bây giờ của chúng ta chuyển thành tìm một bao dưới từ tập các điểm (i, pref[i]).  
```
double slope(int i,int j){	return 1.0 * (a[j] - a[i])/ (j - i); }
line.push_back(0);
for(int i=1;i<=n;++i){
	while (line.size() >= 2){
		#define last (line.size() - 1)
		if (slope(line[last-1], line[last]) > slope(line[last-1], i) line.pop_back();
			else break;
		}
		line.push_back(i);
	}
	line.push_back(n+1);
```  
Từ đó in ra kết quả.  
## [GROUP](https://vn.spoj.com/problems/GROUP/)  
> Cho n $\leq$ 300000 cặp số (x,y) ($1 \leq x, y \leq 1000000$). Ta có thể nhóm một vài cặp số lại thành một nhóm. Giả sử một nhóm gồm các cặp số thứ $a_1, a_2, ..., a_m$ thì chi phí cho nhóm này sẽ là $max(x_{a_1}, x_{a_2}, ..., x_{a_m}) * max(y_{a_1}, y_{a_2}, ..., y_{a_m})$.  

**Nhận xét 1**    
Ta dễ thấy có một vài điểm $(x_i, y_i)$ không quan trọng, tức là tồn tại 1 giá trị $(x_j, y_j)$ mà ở đó: $x_j \geq x_i$ và $y_i \geq y_j$. Khi đó, ta có thể thêm tập $(x_i, y_i)$ và trung với tập $(x_j, y_j)$ mà chi phí không thay đổi.  
Từ đó ta lọc các tập không quan trọng ra bằng các sắp xết giảm dần theo giá trị x, sau khi lọc xong ta thấy rằng tập quan trọng có tính chất:
$x_i \geq x_j, y_i \leq y_j$ với $i \leq j$.  
Từ đó, ta có công thức QHĐ: F[i] là chi phí để phân i điểm đầu tiên thành các nhóm. Ta sẽ thấy rằng mình sẽ phải chọn các điểm liên tiếp nhau.  
Khi đó ta có công thức:  
```
F[i] = min(F[j-1] + X[j] * Y[i]
```  
Với công thức này, ta có kết quả với $O(N^2)$.  
**Nhận xét 2**  
Nhận thấy rằng đây là kết quả có dạng đường thẳng `y = a*x + b`  
với x = Y[i], y = F[i], a = X[j], b = F[j-1].  
Nó sẽ tương tự với bài toán cơ bản.  
Từ đó ta nghĩ đến việc sử dụng bao lồi.  
