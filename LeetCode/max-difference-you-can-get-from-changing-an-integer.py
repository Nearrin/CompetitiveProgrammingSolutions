
def f(a):
    a=str(a)
    if a=='9'*len(a):
        return int(a)
    i=0
    while a[i]=='9':
        i+=1
    return int(''.join([c if c!= a[i]else '9'for c in a]))
def g(a):
    a=str(a)
    if a[0]!='1':
        return int(''.join([c if c!= a[0]else '1'for c in a]))
    i=1
    while i<len(a) and a[i] in '01':
        i=i+1
    if i==len(a):
        return int(a)
    return int(''.join([c if c!= a[i]else '0'for c in a]))
    
class Solution(object):
    def maxDiff(self, a):
        return f(a)-g(a)

