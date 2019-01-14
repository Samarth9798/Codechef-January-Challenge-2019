test=int(input())
while test:
    string = input()
    arr=string.split()
    try:
        i=arr.index("not")
        print("Real Fancy")
    except:
        print("regularly fancy")
    test-=1
