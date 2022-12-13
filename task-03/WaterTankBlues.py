tank=[]
sumlist=[]

t=int(input(""))
for i in range(t):
    foo=0
    n=int(input(""))
    tank=map(int,input().split(" ",(n-1)))

    fac=list(tank)

    j=0
    while fac[j]==0:
        j=j+1
    
    tanks=fac[j:n-1]

    zero= tanks.count(0)

    foo=sum(tanks)
    sumlist.append(foo+zero)

for i in range(t):
    print(sumlist[i])