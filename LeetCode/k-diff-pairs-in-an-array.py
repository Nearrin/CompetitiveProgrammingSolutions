class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        from collections import defaultdict
        cnt=defaultdict(int)
        if k<0:
            return 0
        #super tricky!!! 1. 重复 2. k=0 3 k<0(有病= =)
        if k==0:
            for v in nums:
                cnt[v]+=1
            return len(set([v for v in nums if cnt[v]>=2]))
        nums=set(nums)
        ans=0
        for v in nums:
            ans+=cnt[v-k]+cnt[v+k]
            cnt[v]+=1
        return ans
        
