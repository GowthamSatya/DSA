class MinHeap:
    def __init__(self, size):
        self.size = size
        self.front = -1
        self.heap= [(-1,-1) for _ in range(self.size)]
    
    def getLeftChild(self, pos):
        return 2*pos

    def getRightChild(self, pos):
        return 2*pos+1

    def getParent(self,pos):
        return pos//2
    
    def isLeaf(self, pos):
        return 2*pos > self.size

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]


    def MinHeapify(self, pos):
        if not self.isLeaf(pos):
            if(self.heap[pos] > self.heap[self.getLeftChild(pos)]
             or self.heap[pos] > self.heap[self.getRightChild(pos)]):

                if(self.heap[pos] > self.heap[self.getLeftChild(pos)]):
                    self.swap(pos, self.getLeftChild(pos))
                    self.MinHeapify(self.getLeftChild(pos))
                else:
                    self.swap(pos, self.getRightChild(pos))
                    self.MinHeapify(self.getRightChild(pos))

    def buildHeap(self):
        for i in range((self.size//2), 0, -1):
            self.MinHeapify(i)

    def insertNode(self,node):
        if self.front >= self.size:
            return 
        self.front +=1
        self.heap[self.front-1] = node

        current = self.front
        while self.heap[current] < self.heap[self.getParent(current)]:
            self.swap(current, self.getParent(current))
            current = self.getParent(current)
    
    def dequeue(self):
        if self.front < 0: 
            return 
        
        idx = self.front
        if self.heap[self.front-1] > self.heap[self.front]:
            idx = self.front-1
        out = self.heap[idx]
        self.heap.pop(idx)
        self.front -=1
        return out

    def displayQueue(self):
        for i in self.heap:
            print(i, end=" ")
        print("\n")

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]
        self.V= size
    
    def addEdge(self, u,v, w, isUndir = True):
        self.graph[u].append((v,w))
        if isUndir:
            self.graph[v].append((u,w))
    
    def printAdjList(self):
        for i in self.graph:
            print(i, end="->")
            for j in i:
                print(j[0], end=" ")
            print("\n")
    
    def dijkshtras(self, source, dest):
        n = len(self.graph)
        dist = [float("inf") for _ in range(n)]
        q = MinHeap(n)
        list = [-1 for _ in range(n)]
        dist[source] = 0
        q.insertNode((dist[source], source))
        while q.front != -1:
            (a,b) = q.dequeue()
            for i in self.graph[b]:
                x = i[0]
                w = i[1]
                if dist[x] > dist[b]+w:
                    dist[x] = dist[b]+w
                    q.insertNode((dist[x], x))
                    list[x] = b
        
        return dist[dest], list

    def printPath(self, list,dest):
        v = dest
        path = []
        path.append(v)
        while list[v] != -1:
            path.append(list[v])
            v = list[v]
        
        path =  path[::-1]
        for i in range(0,len(path)-1):
            print(path[i], end="->")
        print(path[-1])

g = Graph(5)
g.addEdge(0,1,1)
g.addEdge(1,2,3)
g.addEdge(2,3,1)
g.addEdge(4,3,2)
# g.addEdge(3,4,3)
# g.addEdge(3,5,2)
# g.addEdge(2,6,4)
# g.addEdge(5,6,1)

d, list = g.dijkshtras(0,4)
print(d)
g.printPath(list,4)






