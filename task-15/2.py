t = int(input())
for _ in range(t):
    n = int(input())
    a, b, c = 1, 2, 3
    esum = 2
    
    while c < n:
        if not c % 2:
            esum += c
        a, b, c = b, c, b + c
        
    print(esum)