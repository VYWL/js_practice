N = int(input())

graph_nodes={}
for i in range(N):
    graph_nodes[i]=0
    
def add(x,y):
    graph_nodes[x]+=1
    graph_nodes[y]+=1

for i in range(N-1):
    x, y = map(int,input().split())
    add(x,y)

for i in graph_nodes:
    if(graph_nodes[i]>1):
        print(i, end=' ')
