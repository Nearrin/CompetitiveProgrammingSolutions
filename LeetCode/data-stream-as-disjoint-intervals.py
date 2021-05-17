class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.a=[]
        self.f=True
        

    def addNum(self, val: int) -> None:
        self.a.append([val,val])
        self.f=False
        
        
    def getIntervals(self) -> List[List[int]]:
        if not self.f:
            b=sorted(self.a)
            self.a=[]
            for i in b:
                if not self.a or self.a[-1][1]+1<i[0]:
                    self.a.append(i)
                else:
                    self.a[-1][1]=max(self.a[-1][1],i[1])
            self.f=True
        return self.a
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
