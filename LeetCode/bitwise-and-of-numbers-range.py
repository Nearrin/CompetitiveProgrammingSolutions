class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        ans=0
        for i in range(0,31):
            if (m>>i)&1 and (m>>i)==(n>>i):
                ans+=2**i
        return ans
