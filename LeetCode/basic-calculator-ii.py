class Solution:
    def f(self,s):
        u=s.pop()
        o=s.pop()
        v=s.pop()
        if o=='+':
            s.append(v+u);
        elif o=='-':
            s.append(v-u);
        elif o=='*':
            s.append(v*u);
        else:
            s.append(v//u);
    def calculate(self, a: str) -> int:
        s=[]
        i=0
        a='('+a+')'
        while i<len(a):
            if a[i]==' ':
                pass
            elif a[i] in '+-':
                while s[-2]in '+-*/':
                    self.f(s)
                s.append(a[i])
            elif a[i] in '*/':
                while s[-2] in '*/':
                    self.f(s)
                s.append(a[i])
            elif a[i]=='(':
                s.append(a[i]);
            elif a[i]==')':
                while s[-2]!='(':
                    self.f(s)
                u=s.pop()
                s.pop()
                s.append(u)
            else:
                j=i
                while j+1<len(a) and ord(a[j+1])-ord('0') in range(10):
                    j+=1
                s.append(int(a[i:j+1]))
                i=j
            i+=1
        return s[0]
