num=input("")
res = list(map(int, str(num)))

i=0
while len(res)!=1:
    if len(res)!=1:
        bleh=sum(res)
        res=list(map(int,str(bleh)))
        i=i+1

print(i)