class Solution:
    def rob(self, nums: List[int]) -> int:
        f=[-1]*len(nums)
        for i in range(len(nums)):
            if not i:
                f[i]=nums[i]
            elif i==1:
                f[i]=max(nums[i],nums[i-1])
            else:
                f[i]=max(f[i-1],nums[i]+f[i-2])
        # cao!
        return f[-1] if f else 0
