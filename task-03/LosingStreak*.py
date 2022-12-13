def factors(n):
    while n>1:
        for i in range(2, n+1):
            if n%i==0:
                n//=i
                yield i
                break

x,y=map(int,input().split())
l=[]
if y%x!=0:
    print(-1)
    exit()
    

if y==0:
    print(-1)
    exit()

if y%x==0:
    for i in factors(y//x):
        l.append(i)
    if l.count(2)+l.count(3)>len(l):
        print(-1)

    elif l.count(2)+l.count(3)==len(l):
        print(l.count(2)+l.count(3))
    else:
        print(-1)


