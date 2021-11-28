inputText = input()
result = ""

for i in range(len(inputText)):
    result += inputText[i]
    if i != len(inputText) - 1:
        result += "__"
    
print(result)