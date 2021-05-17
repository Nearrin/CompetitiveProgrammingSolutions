class Solution:
    def calculate(self, a: str) -> int:
        s=[]
        i=0
        a='('+a+')'
        while i<len(a):
            if a[i]==' ':
                pass
            elif a[i] in '+-':
                while s[-2]!='(':
                    u=s.pop()
                    o=s.pop()
                    v=s.pop()
                    # print(u,o,v)
                    if o=='+':
                        s.append(v+u)
                    else:
                        s.append(v-u)
                s.append(a[i])
            elif a[i]=='(':
                s.append(a[i]);
            elif a[i]==')':
                while s[-2]!='(':
                    u=s.pop()
                    o=s.pop()
                    v=s.pop()
                    # print(u,o,v)
                    if o=='+':
                        s.append(v+u)
                    else:
                        s.append(v-u)
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
