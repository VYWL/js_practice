n=int(input())
bear=[]
for i in range(n):
    a=list(map(int, input().split()))
    bear.append(a)
for i in range(n):
    x=bear[i][0]
    y=bear[i][1]
    z=bear[i][2]
    w=bear[i][3]
    if(z/w>y/x):
        print(-1)
    else:
        gap=(5*((w-x)**2)*((x**2+y**2)/(x**2)))/((y/x)*w-z)
        ans=gap**(1/2)
        ans=int(ans+1)
        if(ans>1000000):
            print(-1)
        else:
            print(ans)
