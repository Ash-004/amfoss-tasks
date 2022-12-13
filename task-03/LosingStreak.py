fact1=[]
fact2=[]
result=[]

def factors(n):
    while n>1:
        for i in range(2, n+1):
            if n%i==0:
                n//=i
                yield i
                break

x,y=map(int,input().split())

fact1=[]
fact2=[]
l=[]

for i in factors(x):
    fact1.append(i)

for i in factors(y):
    fact2.append(i)

if x==y:
    print(0)
    exit()
# print(fact2)
if y>x:    
    for i in fact1:
        if i in fact2:
            fact2.remove(i)


if fact1.count(2)>fact1.count(2) or fact1.count(3)>fact2.count(3):
    print(-1)
    exit
    
    if set(fact2)=={2} or set(fact2)=={3} or set(fact2)=={2, 3} or set(fact2)=={3, 2}:
        print(len(fact2))

    else:
        print(-1)

# print(fact2)
# print(fact1)