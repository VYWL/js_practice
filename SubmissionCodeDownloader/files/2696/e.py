import math
            
N, M, K = map(int, input().split())
answer = 0
Dold = abs(N-M)
remainValue = N*M

while remainValue > 1:
    remainValue -= 1
    isOK = False
    impossible = False
    
    if remainValue < K:
        answer += remainValue
        break
    
    for i in range(int(math.sqrt(remainValue)), -1, -1):
        if abs(i - (remainValue//i)) > Dold + K:
            impossible = True
            break
        else:
            if remainValue % i == 0:
                isOK = True
                break
    if isOK:
        answer += 1
        continue
    
    if impossible:
        break    

print(answer)
'''
def prime_fac(x):
    result = []
    result.append((1, x))
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            result.append((i, x // i))
    return result
            
N, M, K = map(int, input().split())
answer = 0
Dold = abs(N-M)
remainValue = N*M

while remainValue > 1:
    remainValue -= 1
    isOK = False
    funResult = prime_fac(remainValue)
    for e in funResult:
        if abs(e[0]-e[1]) <= Dold + K:
            isOK = True
            break
    if isOK:
        answer += 1
        continue
    else:
        break
print(answer)
'''