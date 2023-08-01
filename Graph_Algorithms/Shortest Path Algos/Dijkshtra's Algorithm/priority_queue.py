class Minheap:
    # constructor
    def __init__(self, maxSize=5):
        self.size = maxSize
        self.front = -1
        self.heap = []

    def getLeftChild(self,idx):
        return 2*idx + 1

    def getRightChild(self,idx):
        return 2*idx + 2

    def getParent(self,idx) :
        return (idx)//2

    def swap(self, p1, p2):
        self.heap[p1], self.heap[p2] = self.heap[p2], self.heap[p1]   

    def heapify(self,idx):
        if not idx*2 > self.size:
            if (self.heap[idx] > self.heap[self.getLeftChild(idx)] or self.heap[idx] > self.heap[self.getRightChild(idx)]):
                if self.heap[self.getLeftChild(idx)] < self.heap[self.getRightChild(idx)]:
                    self.swap(idx, self.getLeftChild(idx))
                    self.heapify(self.getLeftChild(idx))
                else:
                    self.swap(idx, self.getRightChild(idx))
                    self.heapify(self.getRightChild(idx))
                
    def isEmpty(self):
        return self.front == -1

    def isFull(self):
        return self.front >= self.size-1

    def buildHeap(self):
        for i in range((self.size//2), 0, -1):
            self.heapify(i)

    # function to enqueue element to priority queue
    def enqueue(self, data):
        if self.isFull():
            print("Heap Overflow")
            return
        
        self.front +=1
        self.heap.append(data)
        curr= self.front
        while self.heap[curr] < self.heap[self.getParent(curr)]:
            self.swap(curr, self.getParent(curr))
            curr = self.getParent(curr)

    # function to dequeue element in O(1) time
    def dequeue(self):
        if(self.isEmpty()):
            return [-1,-1]
        pop = self.heap[self.front]
        self.heap.pop()
        self.front -=1
        return pop

    # function to displayQueue
    def displayQueue(self):
        if len(self.heap) == 0:
            print("Queue Empty")
            return

        for i in self.heap:
            if i != 0:
                print(i, end=" ")
        print()