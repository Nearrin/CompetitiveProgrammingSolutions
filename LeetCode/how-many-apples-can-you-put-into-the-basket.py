class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr=sorted(arr)
        cur=5000
        ans=0
        for v in arr:
            if v<=cur:
                cur-=v
                ans+=1
        return ans
