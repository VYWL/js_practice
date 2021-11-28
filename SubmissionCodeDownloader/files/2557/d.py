
def mm(X,Y):
    result = []
    for i in range(len(X)):
        a_row = []
        for j in range(len(Y[0])):
            sum = 0
            for k in range(len(X[0])):
                sum += X[i][k] * Y[k][j]
            a_row.append(sum)
        result.append(a_row)
    return result

n = int(input())

X = []
Y = []
Z = []
for i in range(3*n):
    b = input()
    b = b.split()
    c = []
    for k in b:
        c.append(int(k))
    if( i <n):
        X.append(c)
    elif i < 2*n:
        Y.append(c)
    elif i < 3*n:
        Z.append(c)

X_answer = []
Y_answer = []
Z_answer = []

if (mm(X,Y) == Z):
    X_answer.append("P")
    Y_answer.append("A")
    Z_answer.append("M")
if(mm(Y,X) == Z):
    X_answer.append("A")
    Y_answer.append("P")
    Z_answer.append("M")
if(mm(X,Z) ==Y):
    X_answer.append("P")
    Y_answer.append("M")
    Z_answer.append("A")
if(mm(Z,X) ==Y):
    X_answer.append("A")
    Y_answer.append("M")
    Z_answer.append("P")
if(mm(Y,Z) == X):
    X_answer.append("M")
    Y_answer.append("P")
    Z_answer.append("A")
if(mm(Z,Y)==X):
    X_answer.append("M")
    Y_answer.append("A")
    Z_answer.append("P")

X_num = 1 * (1 if "P" in X_answer else 0) + 2 * (1 if "A" in X_answer else 0) + 4 * (1 if "M" in X_answer else 0)
Y_num = 1 * (1 if "P" in Y_answer else 0) + 2 * (1 if "A" in Y_answer else 0) + 4 * (1 if "M" in Y_answer else 0)
Z_num = 1 * (1 if "P" in Z_answer else 0) + 2 * (1 if "A" in Z_answer else 0) + 4 * (1 if "M" in Z_answer else 0)

print(X_num)
print(Y_num)
print(Z_num)
