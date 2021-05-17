class Solution:
    def reverseBits(self, n: int) -> int:
        m=0
        for i in range(32):
            m=(m<<1)+(n&1)
            n>>=1
        return m
        
