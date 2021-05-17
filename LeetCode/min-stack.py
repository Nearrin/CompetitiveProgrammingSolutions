class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.v=[]
        self.m=[]
        

    def push(self, x: int) -> None:
        if not self.v:
            self.v.append(x)
            self.m.append(x)
        else:
            self.v.append(x)
            self.m.append(min(self.m[-1],x))
        

    def pop(self) -> None:
        self.v.pop(-1)
        self.m.pop(-1)
        

    def top(self) -> int:
        return self.v[-1]
        

    def getMin(self) -> int:
        return self.m[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
