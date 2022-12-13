n=int(input(""))
cordlist=[]
point=0

for i in range(n):
    cord=list(map(int,input().split()))
    cordlist.append(cord)
    
for i in cordlist:
    c1=i[0]
    c2=i[1]
    a=0
    b=0
    c=0
    d=0
    
    for j in cordlist:
        if j[0]==c1:
            if j[1]>c2 and a==0:
                a+=1
                
            if j[1]<c2 and b==0:
                b+=1
                
        elif j[1]==c2:
            if j[0]>c1 and c==0:
                c+=1
                
            if j[0]<c1 and d==0:
                d+=1
                
    if a!=0 and b!=0 and c!=0 and d!=0:
        point+=1
        
print(point)