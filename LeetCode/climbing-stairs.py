class Solution:
    def climbStairs(self, n: int) -> int:
        fn_1=0
        fn=1
        for i in range(n):
            nxt=fn+fn_1
            fn_1,fn=fn,nxt
        return fn
