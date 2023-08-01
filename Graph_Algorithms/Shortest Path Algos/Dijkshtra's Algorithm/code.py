from priority_queue import Minheap

class Graph:
    def __init__(self, len):
        self.V = len
        self.graph = [[] for _ in range(len)]

    def printAdjList(self):
        for i in range(len(self.graph)):
            print(i, end=' : ')
            print(self.graph[i])
        print("\n")
        
    def addEdge(self,u,v,w, isUndir = False):
        self.graph[u].append((v,w))
        if isUndir:
            self.graph[v].append((u,w))

    def dijkshtras(self,s,dest):
        n = len(self.graph)
        queue = Minheap(n)
        list = [0]*len(self.graph)
        dist = [float('inf') for i in range(n)]
        dist[s] = 0
        queue.enqueue((dist[s], s))
        while(queue.isEmpty() != 1):
            [a,b] = queue.dequeue()
            for i in self.graph[b]:
                x = i[0]
                w = i[1]    
                if dist[x] > dist[b] + w:
                    dist[x] = dist[b] + w
                    queue.enqueue((dist[x],x))
                    list[x] = b
        return list, dist[dest]

    def printPath(self,list,dest):
        if dest not in list:
            return None
        v = dest
        path = []
        while v != -1:
            path.append(v)
            v = list[v]
            list[v] = -1
        return path[::-1]

if __name__ == "__main__":
    g = Graph(4)
    g.addEdge(0,1,10)
    g.addEdge(0,3,5)
    g.addEdge(3,2,6)
    g.addEdge(2,1,8)
    g.addEdge(3,1,1)
    g.addEdge(1,3,7)
    g.printAdjList()
    [lst,d] = g.dijkshtras(0,3)
    print("Shortest Path is : ",d)
    print("Path : ",g.printPath(lst,3))
    
