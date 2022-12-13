words=list(map(int, input("").split(' ',2)))
foo=[]

for i in range(int(words[1])):
    k=list(input("").split(' '))
    
    foo.append(k)
    
spell=list(input("").split(' '))
harrysspell=[]

for j in spell:
    for m in foo:
        if m[0]==j:
            if len(m[0])<=len(m[1]):
                harrysspell.append(m[0])
                break
            
            else:
                harrysspell.append(m[1])
                break
            
        else:
            continue
for i in range(words[0]):
    print(harrysspell[i], end=" ")  