class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        a=[min(x,y)for x,y in rectangles]
        m=max(a)
        return len([x for x in a if x==m])
