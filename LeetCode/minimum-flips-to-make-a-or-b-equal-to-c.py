class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        if a==b and b==c:
            return 0
        x=a%2
        y=b%2
        z=c%2
        ans=self.minFlips(a//2,b//2,c//2)
        if max(x,y)!=z:
            if x==1 and y==1:
                ans+=2
            else:
                ans+=1
        return ans
        
        
