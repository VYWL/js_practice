the_input = input()

output = ""

N = len(the_input)

i = 0

for i in range(N):
    if N > 0:
        output += the_input[i]
    if i != (N-1):
        output += "__"

print(output)
    
