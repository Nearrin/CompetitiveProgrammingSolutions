class Vector2D:

    def __init__(self, v: List[List[int]]):
        self.v=[i for t in v for i in t]
        self.i=0

    def next(self) -> int:
        self.i+=1
        return self.v[self.i-1]

    def hasNext(self) -> bool:
        return self.i<self.v.__len__()


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()
