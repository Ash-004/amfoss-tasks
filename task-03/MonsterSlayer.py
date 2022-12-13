n=int(input(""))

l=[]
for i in range(n):
    li=list(map(int,input("").split(" ",(n))))
    l.append(li)
    
for i in l:
    while True:
        if i[0]==0:
            i.pop(0)
        elif i[-1]==0:
            i.pop(-1)
        else:
            break
    if i[0]>=i[1] and i[0]!=1:
        print("NO")
        
    else:
        if i[1]%i[0]!=0 and i[1]%i[0]!=1:
            print("NO")
        elif i.count(0)>=1:
            print("NO")
        else:
            print("YES")