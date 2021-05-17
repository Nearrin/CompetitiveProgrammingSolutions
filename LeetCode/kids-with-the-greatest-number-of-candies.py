class Solution(object):
    def kidsWithCandies(self, a, b):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        ans=[]
        for i in range(len(a)):
            ans.append(a[i]+b>=max(a[j] for j in range(len(a)) if j!=i))
        return ans
