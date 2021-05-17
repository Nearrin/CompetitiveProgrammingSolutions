class Solution:
    def isHappy(self, n: int) -> bool:
        vis=set()
        while True:
            if n==1:
                return True
            if n in vis:
                return False
            vis.add(n)
            n=sum(map(lambda x:int(x)**2,str(n)))
