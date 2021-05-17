class Solution:
    def sumOddLengthSubarrays(self, a: List[int]) -> int:
        ans=0
        for i in range(len(a)):
            for j in range(i,len(a)):
                if (j-i+1)%2==1:
                    ans+=sum(a[i:j+1])
        return ans
