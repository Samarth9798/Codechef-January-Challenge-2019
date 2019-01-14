test = int(input())
while test:
    N,P = map(int,input().split())
    i = (N//2) + 1
    max_score = N % i
    ways = 0
    if max_score == 0:
        ways = P*P*P
    else:
        temp = (P - (max_score + 1)) + 1
        ways = temp * temp
        if P > N:
            temp2 = P - N
            ways = ways + (temp2 * temp) + (temp2 * temp2)
    print(ways)
    test-=1
