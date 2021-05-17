class Solution:
    def reverse(self, x: int) -> int:
        if x<0:
            return -self.reverse(-x)
        t=int(str(x)[::-1])
        if t<-(1<<31) or t>(1<<31)-1:
            t=0
        return t
