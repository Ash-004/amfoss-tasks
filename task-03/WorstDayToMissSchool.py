n=int(input(""))

s=[]
s=map(int,input("").split(" ",(n-1)))
group=list(s)

four=group.count(4)
three=group.count(3)
two=group.count(2)
one=group.count(1)


if three==one:
    if two%2==0:
        print(int(four+three+two/2))
    elif two%2!=0:
        print(int(four+three+(two//2)+1))


elif three<one:
    if two%2==0:
        if (one-three)%4==0:
            print(int(four+three+two/2+(one-three)/4))
        else:
            print(int(four+three+two/2+(one-three)//4+1))
    elif two%2!=0:
        if (one-three)<=2:
            print(int(four+three+two//2+1))
        elif (one-three)>2 and (one-three-2)%4==0:
            print(int(four+three+two//2+1+(one-three-2)/4))
        elif (one-three)>2 and (one-three-2)%4!=0:
            print(int(four+three+two//2+1+(one-three-2)//4+1))
            


elif three>one:
    if two%2==0:
        print(int(four+one+two/2+(three-one)))
    elif two%2!=0:
        print(int(four+one+two//2+(three-one)+1))

else: 
    exit()
    