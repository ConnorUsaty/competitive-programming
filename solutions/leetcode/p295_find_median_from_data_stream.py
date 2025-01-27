class MedianFinder:
    def __init__(self):
        self.small = [] # maxHeap
        self.large = [] # minHeap
        
    def addNum(self, num: int) -> None:
        if self.large and num > self.large[0]:
            heapq.heappush(self.large, num)
        else:
            heapq.heappush(self.small, -1*num)

        if len(self.small) > len(self.large)+1:
            val = -1*heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        if len(self.large) > len(self.small)+1:
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -1*val)

    def findMedian(self) -> float:
        if len(self.small) < len(self.large):
            med = 1.0*self.large[0]
        elif len(self.small) > len(self.large):
            med = -1.0*self.small[0]
        else:
            med = (-1.0*self.small[0]+self.large[0]) / 2.0

        return med
        
        
# Similar idea to how we found median in two sorted arrays
# We know that for a median we need to equal partitions on either side, then the median will be in the middle
# Use a minHeap and a maxHeap to parition the elements into the higher and lower halves, then grab the middle element (median) when needed

# python has minHeap by default, to make maxHeap * by -1
# heappop() returns and removes element in Python, use heap[0] to only access and not remove
# python instance variables all declared in __init__ (one and only constructor)