class Solution:
    def convertToTitle(self, n: int) -> str:
        ans=[]
        while n:
            t=n%26
            if t==0:
                t=26
            ans.append(chr(ord('A')+t-1))
            n=(n-1)//26
        return ''.join(ans)[::-1]
