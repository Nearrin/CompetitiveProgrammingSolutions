class NumArray:

    def __init__(self, nums: List[int]):
        self.s=[]
        for v in nums:
            if not self.s:
                self.s.append(v)
            else:
                self.s.append(v+self.s[-1])
        

    def sumRange(self, i: int, j: int) -> int:
        if not i:
            return self.s[j]
        return self.s[j]-self.s[i-1]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
