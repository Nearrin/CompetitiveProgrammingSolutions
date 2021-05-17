class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        cnt=0
        for v in nums:
            if v==target:
                cnt+=1
        return cnt>len(nums)/2
