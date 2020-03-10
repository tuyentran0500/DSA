# Các bài toán về luồng (Flow).
Trong chuyên mục này, chúng ta sẽ tập trung vào các bài toán về luồng:  
Một số bài tập tham khảo:  
+ Level 0: [NLFLOW spoj](http://vn.spoj.com/problems/NKFLOW/)  
+ Level 1: http://codeforces.com/contest/546/problem/E  
+ Level 1: http://codeforces.com/contest/653/problem/D  
+ Level 1: http://codeforces.com/contest/510/problem/E  
+ Level 2: http://vn.spoj.com/problems/MOBIVINA/  
+ Level 2: http://codeforces.com/gym/100523/problem/I  
+ Level 3: http://vn.spoj.com/problems/MINCOST/  
+ Level 3: http://codeforces.com/problemset/gymProblem/100878/D  
## A. Kiến thức về luồng:  
### Mạng luồng (FLow Network).  
Mạng luồng là 1 đồ thị **có hướng** thỏa mãn.  
- Có 2 đỉnh đặc biệt:  
    + Source: Đỉnh phát  
    + Sink: Đỉnh thu.  

- Với mỗi cung (u,v) gọi một số thực dương c(u,v) là sức chứa.  
Ta biểu diễn mạng luồng G = (V,s,t,c) với V là tập đỉnh, c: V*V đại diện cho sức chứa của các cặp (u,v).  
### Luồng hợp lệ (Admissible flows).  
Một luồng hợp lệ trên mạng G là 1 hàm f: V*V --> R thỏa mãn.  
- Luồng trên mỗi cung không vượt quá sức chứa của nó: f(u,v) <= c(u,v).  
- Đối xứng: f(u,v) = -f(v,u).  
- Bảo toàn luồng qua mỗi đỉnh: Với mọi u thuộc V, sum(f(u,v)) = 0. (v thuộc V).  
### Mạng thặng dư (Residual network).  
Mạng thặng du cho ta biết sức chứa còn lại trên mạng khi đã gửi 1 số luồng cho nó.  
```r(u,v) = c(u,v) - f(u,v).```  
### Bài toán luồng cực đại trên mạng (Maximum flow).  
Cho một mạng, chúng ta cần tìm một luồng cực đại sao cho tổng luồng ra từ đỉnh phát cũng như luồng vào của đỉnh thu là cực đại.  
Ta có thể đơn giản hóa bài toán:  
+ Coi `flows network` là 1 hệ thống các ống nước.  
+ Nhiệm vụ của ta là tìm cách điều phối nước từ đỉnh phát sao cho thu được lượng nước tối đa có thể.  
### Thuật toán.  
#### Ford-Fulkerson method.  
Ý tưởng chính của phương pháp Ford-Fulkerson là tăng dần giá trị của luồng trên mạng cho khi nó đạt cực đại.  
Với mỗi bước, trên mạng G hiện tại, chúng ta tìm một đường đi từ s-t mà vẫn có thể gửi luồng qua được, đường đi này gọi là đường tăng luồng (augmenting path).  
Thuật toán kết thúc khi ta không còn tìm thấy đường tăng luồng nữa.  
Có nhiều cách tìm đường tăng luồng, tuy nhiên ta có 2 cách phổ biến nhất:  
- Thuật toán Edmond-Karp: Chọn đường đi có ít cạnh nhất.  
- Thuật toán Dinic: Phân tầng đồ thị mà các đỉnh thuộc các tầng khác nhau, nơi ta chỉ quan tâm đến những đỉnh có thể đến được đỉnh cuối cùng, được gọi là thuật toán Dinic.  
##### Thuật toán Dinic.  
- Đầu tiên ta bfs() toàn đồ thị để tìm những cạnh có thể đi tạo luồng (c(u,v) > f(u,v)), sau đó dựng 1 đồ thị phân tầng.  
```
bool bfs(){
	fill(d,d+1+n, 1e9);
	queue<int> q; d[s]=0;  q.push(s);
	while (q.size()){	int u = q.front(); q.pop(); 
		for(int v=1;v<=n;++v){
			if(d[u]+1<d[v] && c[u][v] > f[u][v]) {
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	return (d[t]!=1e9);
}
```  
- Sử dụng dfs() trên đồ thị mới dựng được để tìm đường tăng luồng.  
```
ll dfs(int u,ll cur_flow){
	if (!cur_flow || u==t) return cur_flow;
	for(int& v=ptr[u]; v<=n ;++v){
		if (d[u]+1!= d[v]) continue;
		ll nxt_flow = dfs(v, min(cur_flow, c[u][v] - f[u][v]));
		if (nxt_flow){
			f[u][v]+=nxt_flow;
			f[v][u]-=nxt_flow;
			return nxt_flow;
		}
	}
	return 0;
}
```
Độ phức tạp thuật toán O(V^2 * E).  
##### Thuật toán Edmond Karp.  
- Đầu tiên, ta cũng sử dụng bfs() để tìm đường tăng luồng và trả về đường tăng luồng ngay lập tức.    
- Lặp lại thao tác trên cho đến khi kết thúc.  
#### Bài toán lát cắt hẹp nhất (Minimum s-t cut).  
Một lát cắt s - t là 1 tập con của E mà khi loại bỏ những cạnh này thì không còn đường đi từ s-t.  
[Max-flow min-cut theorem](https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem) là 1 định luật nổi tiếng về quan hệ giữa luồng cực đại và lát cắt hẹp nhất. Định lý này cho thấy rằng trên một mạng luồng thì giá trị luồng cực đại bằng với giá trị lát cắt hẹp nhất.  
## B. Một số bài toán.  
### Bài toán 1: [Soldier and Traveling CF546E](https://codeforces.com/contest/546/problem/E)  
#### 1. Đề bài:  
Có n thành phố và m đường đi kết nối giữa các thành phố, thành phố thứ i có a(i) chiến binh.  
Sau khi giải ngũ, chiến binh ở thành phố u có thể quyết định ở lại thành phố đó để lập nghiệp, hoặc chuyển sang thành phố bên cạnh bằng các di chuyển tối đa 1 đường đi.  
Kiểm tra xem liệu sau khi giải ngũ, liệu có khả năng nào ở thành phố thứ i sẽ có chính xác b(i) chiến binh.  
**Giới hạn:**
- n <= 100.
- m <= 200.
#### 2. Lời giải:  










