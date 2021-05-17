class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        xsum=[]
        ans=[]
        for v in arr:
            if not xsum:
                xsum.append(v)
            else:
                xsum.append(v^xsum[-1])
        for l,r in queries:
            if l==0:
                ans.append(xsum[r])
            else:
                ans.append(xsum[r]^xsum[l-1])
        return ans
                
