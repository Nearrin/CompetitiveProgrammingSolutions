class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a)<len(b):
            a,b=b,a
        b="0"*(len(a)-len(b)+1)+b
        a="0"+a
        c=[0]*len(a)
        a=a[::-1]
        b=b[::-1]
        cr=0
        for i in range(len(c)):
            this=int(a[i])+int(b[i])+cr
            cr=int(this//2)
            this%=2
            c[i]=str(this)
        while c[-1]=='0'and len(c)>1:
            c.pop(-1)
        c=''.join(c[::-1])
        return c
