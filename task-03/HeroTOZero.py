def checklevel(lvl):
    if len(lvl) == len(set(lvl)):
        return False
    else:
        return True


mana=[]
t=int(input(""))

for i in range(t):
    n=int(input(""))

    for j in range(n):
        levels=list(map(int,input("").split(" ",(n-1))))

        sum=0
        

        if 0 in levels:
            z=levels.count(0)
            sum=+ sum+(n-z)
            mana.append(sum)

        elif checklevel(levels)==True:
            sum=+ sum+(n)
            mana.append(sum)
        
        else:
            sum=+ sum+(n+1)
            mana.append(sum)

        break
for i in range(t):
    print(mana[i])

