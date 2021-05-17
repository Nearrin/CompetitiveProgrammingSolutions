class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        fmi,fmx=nums[0],nums[0]
        ans=fmi
        for v in nums[1:]:
            fmi_=min(v,v*fmi,v*fmx)
            fmx_=max(v,v*fmi,v*fmx)
            fmi=fmi_
            fmx=fmx_
            ans=max(ans,fmi,fmx)
        return ans
        
