class Solution:
    def shuffle(self, a: List[int], n: int) -> List[int]:
        ans=[]
        for x,y in zip(a[:n],a[n:]):
            ans.append(x)
            ans.append(y)
        return ans
