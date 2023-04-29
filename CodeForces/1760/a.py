t = int(input())
for _ in range ( int(t) ):
    a = [int(x) for x in input().split()]
    a.sort()
    print ( a[1] )
