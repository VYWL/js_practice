

def mm(a, ux,uy, dx,dy):
    
    if ( ux == dx and uy == dy):
        return a[ux][uy]
    else:
        # print(ux, uy, dx, dy)
        # print(ux , uy, int((ux+dx)/2), int((uy+dy)/2))
        # print(int((ux+dx)/2)+1, uy, dx, int((uy+dy)/2))
        # print(ux, int((uy+dy)/2) +1, int((ux+dx)/2), dy)
        # print(int((ux+dx)/2)+1, int((uy+dy)/2) +1, dx, dy)
        res_arr = []
        # return 1
        res_arr.append(mm(a, ux , uy, int((ux+dx)/2), int((uy+dy)/2)) )
        res_arr.append(mm(a, int((ux+dx)/2)+1, uy, dx, int((uy+dy)/2)) )
        res_arr.append(mm(a, ux, int((uy+dy)/2) +1, int((ux+dx)/2), dy) )
        res_arr.append(mm(a, int((ux+dx)/2)+1, int((uy+dy)/2) +1, dx, dy))
        res_arr.sort()
        return res_arr[1]

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
    print(mm(arr, 0,0, n-1,n-1))