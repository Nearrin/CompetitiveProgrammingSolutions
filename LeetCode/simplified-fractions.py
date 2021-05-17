def gcd(a,b):
    if b:
        return gcd(b,a%b)
    return a
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        ans=[]
        for i in range(1,n+1):
            for j in range(1,i):
                if gcd(i,j)==1:
                    ans.append('%d/%d'%(j,i))
        return ans
