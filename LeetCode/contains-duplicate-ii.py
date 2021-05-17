class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # = = you bei ken le!!!
        if not nums:
            return False
        vals=set()
        l=0
        r=0
        vals.add(nums[0])
        while r+1<len(nums):
            if r-l==k:
                vals.remove(nums[l])
                l+=1
            r+=1
            if nums[r] in vals:
                return True
            vals.add(nums[r])
        return False
