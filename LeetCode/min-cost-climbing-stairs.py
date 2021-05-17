class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        f=[i for i in cost]
        for i in range(2,len(cost)):
            f[i]=min(f[i-1],f[i-2])+cost[i]
        return min(f[-1],f[-2])
