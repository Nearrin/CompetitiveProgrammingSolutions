#这题居然错了两次
#第一次看错写成union
#第二次没去重。。。。
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1=set(nums1)
        return list(set([i for i in nums2 if i in s1]))
        
