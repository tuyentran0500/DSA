N = 351
isPrime = [1] * N
for i in range(2, N):
	if (isPrime[i]):
		for j in range(i*i,N,i):
			isPrime[j] = 0
pList = [1]
for i in range(2, N):
	if (isPrime[i]):
		pList.append(i)
m = len(pList)
# DP
dp = [ [1] * (m+1) for i in range(N+1)]
for i in range(1,N):
	for j in range(m):
		nTime = 0
		while (nTime * pList[j] <= i):
			# print(i, pList[j], nTime, i - pList[j] * nTime)
			if (nTime):
				dp[i][j+1] = max(dp[i][j+1], dp[i - pList[j] * nTime][j] * pList[j])
			else:
				dp[i][j+1] = max(dp[i][j+1], dp[i][j])
			nTime+=1
t = int(input())
# for i in range(7):
# 	for j in range(m+1):
# 		print(dp[i][j], end = " ")
# 	print()
while t > 0:
	t-=1
	n =int(input())
	print(dp[n][m])

			