str = input()
for ch in str[:len(str) -1]:
    print(ch, end= '__')
print(str[len(str) -1])