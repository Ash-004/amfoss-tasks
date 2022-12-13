a,b=input("").split()
s=int(a)
m=int(b)
if m>s:
    print(-1)

elif s==m:
    print(m)

elif s>m:
    for y in range(s//2,0,-1):
        for x in range(s):
            # print(x,y)
            if 2*y+x==s and (x+y)%m==0:
                print(x+y)
                exit()

    
else:
    print(-1)
            