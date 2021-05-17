class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        cur=n-1
        for i in range(n-2,-1,-1):
            if cur-i>nums[i]:
                continue;
            else:
                cur=i
        return cur==0
