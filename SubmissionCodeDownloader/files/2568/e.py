import math

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