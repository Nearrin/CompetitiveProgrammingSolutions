class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], 
        initialBoxes: List[int]) -> int:
        ans=0
        while initialBoxes:
            u=initialBoxes.pop(-1)
            ans+=candies[u]
            candies[u]=0
            for v in keys[u]:
                status[v]|=1
                if status[v]==3 and candies[v]:
                    initialBoxes.append(v)
            for v in containedBoxes[u]:
                status[v]|=2
                if status[v]==3 and candies[v]:
                    initialBoxes.append(v)
        return ans

