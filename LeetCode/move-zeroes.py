class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pz=0
        pnz=-1
        while pz<len(nums) and nums[pz]!=0:
            pz+=1
        if pz==len(nums):
            return
        while pz<len(nums):
            #print(pz)
            pnz+=1
            if pnz<pz:
                pnz=pz
            while pnz<len(nums)and nums[pnz]==0:
                pnz+=1
            if pnz==len(nums):
                return
            nums[pz],nums[pnz]=nums[pnz],nums[pz]
            pz+=1
            while pz<len(nums) and nums[pz]!=0:
                pz+=1
        
