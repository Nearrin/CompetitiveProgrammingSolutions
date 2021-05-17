class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        c=0
        l=max(len(num1),len(num2))
        ans=[]
        for i in range(l):
            j1=len(num1)-i-1
            j2=len(num2)-i-1
            t=0
            if j1>=0:
                t+=ord(num1[j1])-ord('0')
            if j2>=0:
                t+=ord(num2[j2])-ord('0')
            t+=c
            c=t//10
            ans.append(chr(ord('0')+t%10))
        if c!=0:
            ans.append(chr(ord('0')+c))
        return ''.join(ans)[::-1]
