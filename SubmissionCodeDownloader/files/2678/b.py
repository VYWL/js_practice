import sys

N, M = map(int, input().split())
errorArr = list(map(int, sys.stdin.readline().rstrip().split()))
X, Y = map(int, input().split())
errorArr.sort(reverse = True)

checkError = 0

while errorArr:
    
    if checkError >= Y:
        break
    
    errorArr.pop()
    checkError += 1
    
    
while errorArr:
    if errorArr[-1] > X:
        break
    else:
        errorArr.pop()
        
print(len(errorArr))