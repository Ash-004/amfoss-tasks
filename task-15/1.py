
import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
        
    a=(n-1)//3
    b=(n-1)//5
    c=(n-1)//15

    s3=3*a*(a+1)//2
    s5=5*b*(b+1)//2
    s15=15*c*(c+1)//2

    print (s3+s5-s15)