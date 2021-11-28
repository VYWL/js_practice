import numpy as np

def mm(a):
    if(len(a) == 2):
        result_arr = []
        result_arr.append(a[0][0])
        result_arr.append(a[0][1])
        result_arr.append(a[1][0])
        result_arr.append(a[1][1])
        result_arr.sort()
        return result_arr[1]
    else:
        a_np = np.array(a)
        result_arr = []
        leftup = a_np[0:int(len(a_np)/2) , 0:int(len(a_np)/2) ]
        leftdown = a_np[ int(len(a_np)/2):int(len(a_np)), 0:int(len(a_np)/2) ]
        rightup = a_np[ 0:int(len(a_np)/2), int(len(a_np)/2):int(len(a_np))]
        rightdown = a_np[int(len(a_np)/2):int(len(a_np)), int(len(a_np)/2):int(len(a_np))]
        result_arr.append(mm(leftup))
        result_arr.append(mm(leftdown))
        result_arr.append(mm(rightup))
        result_arr.append(mm(rightdown))
        result_arr.sort()
        return result_arr[1]

n = int(input())

arr = []
for i in range(n):
    line = input()
    line = line.split()
    row = []
    for l in line:
        row.append(int(l))
    arr.append(row)

if n == 1:
    print(arr[0])
else:
    print(mm(arr))