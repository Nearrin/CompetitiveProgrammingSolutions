class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans=[]
        for i in range(len(nums)):
            while nums[i]!=-1 and nums[i]!=i+1:
                if nums[nums[i]-1]==nums[i]:
                    ans.append(nums[i])
                    nums[i]=-1
                else:
                    t=nums[i]-1
                    nums[i],nums[t]=nums[t],nums[i]
        return ans
