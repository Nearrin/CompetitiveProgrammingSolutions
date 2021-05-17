class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        #tiao zhen fa xian ran
        return sum(sorted(nums)[::2])
