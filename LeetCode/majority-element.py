class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cur_v=None
        cur_c=0
        for i in nums:
            if not cur_v:
                cur_v=i
                cur_c=1
            elif cur_v==i:
                cur_c+=1
            else:
                cur_c-=1
                if cur_c==0:
                    cur_v=None
        return cur_v
