class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        ans=[]
        for u,v in zip((v for v in A if v%2==0),(v for v in A if v%2==1)):
            ans.append(u)
            ans.append(v)
        return ans
