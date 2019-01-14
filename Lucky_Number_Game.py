test = int(input())
while test:
    n,a,b = map(int,input().split())
    arr = list(map(int,input().split()))
    aa = 0
    bb = 0
    cc = 0
    for i in range(0,n):
        if arr[i]%a==0 and arr[i]%b==0:
            cc+=1
        elif arr[i]%a==0:
            aa+=1
        elif arr[i]%b==0:
            bb+=1
    if a==b or b%a==0:
        print("BOB")
    elif a%b==0:
        print("ALICE")
    elif cc==0:
        if aa > bb:
            print("BOB")
        else:
            print("ALICE")
    elif cc > 0:
        if aa>=bb:
            print("BOB")
        else:
            print("ALICE")
    test-=1
