class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        from functools import reduce
        return reduce(lambda x,y:x*y,map(int,str(n)))-reduce(lambda x,y:x+y,map(int,str(n)))
        
