class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        else:
            s=self.countAndSay(n-1)
            r=""
            i=0
            while i<len(s):
                j=i
                while j+1<len(s)and s[j+1]==s[j]:
                    j+=1
                r+=str(j-i+1)+s[i]
                i=j+1
            return r
                
