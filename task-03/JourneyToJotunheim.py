t=int(input(""))
results=[]

for i in range(t):
    keys=[]
    n=int(input(""))
    keys=map(int,input("").split(" ", 3))
    portal=list(keys)
    
    if portal[n-1]!=0:
        poo=int(portal[n-1])
        if portal[poo-1]!=0:
            results.append("YES")
        else:
            results.append("NO")
    else:
        results.append("NO")        
            
for i in range(t):
    print(results[i])