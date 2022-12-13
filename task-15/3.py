#!/bin/python3

import sys
def check(x):
    if x == 2:
        return True
    if x%2==0:
        return False
    i=3
    while i**2 <= x:
        if x%i==0:
            return False
        i+=2
    return True
    

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
 
    
    for i in range(1,n+1):
        if n%i==0:
            if check(n//i):
                print(n//i)
                break
            
