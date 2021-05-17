class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for x in range(0,len(nums)+1):
            if len([i for i in nums if i>=x])==x:
                return x
        return -1
