class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        s=[]
        for v in nums:
            if not s:
                s.append(v)
            else:
                s.append(v+s[-1])
        ans=[]
        for i in range(k-1,len(nums)):
            if i==k-1:
                ans.append(s[i])
            else:
                ans.append(s[i]-s[i-k])
        return max(ans)/k
        
