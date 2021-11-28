S = input()
print("".join([s+"__" if i != len(S)-1 else s for i,s in enumerate(S)]))