input = "WELCOME"

output = ""

N = len(input)

i = 0

for i in range(N):
    if N > 0:
        output += input[i]
    if i != (N-1):
        output += "__"

print(output)
    
