class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        # notice radix sort is also O(n) if we consider the range constant!
        # but there is a really great solution here (i was not able to come up with it myself...i read the solution)
        if len(nums)<2:
            return 0
        mi=min(nums)
        mx=max(nums)
        if mi==mx:
            return 0
        n=len(nums)
        q=mx-mi
        d=max(q//(n-1)-1,1)
        nums=[i-mi for i in nums]
        mx-=mi
        bks=[[]for i in range(mx//(d+1)+1)]
        for i in range(len(nums)):
            bks[nums[i]//(d+1)].append(nums[i])
        ans=[]
        bks=[i for i in bks if i]
        for i in range(1,len(bks)):
            ans.append(min(bks[i])-max(bks[i-1]))
        return max(ans)
            
