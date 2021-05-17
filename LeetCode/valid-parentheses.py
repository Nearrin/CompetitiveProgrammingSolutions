class Solution:
    def isValid(self, s: str) -> bool:
        q=[]
        for i in s:
            if i in '({[':
                q.append(i)
            elif not q:
                return False
            elif q[-1]=='('and i==')':
                q.pop(-1)
            elif q[-1]=='{'and i=='}':
                q.pop(-1)
            elif q[-1]=='['and i==']':
                q.pop(-1)
            else:
                return False
        if q:
            return False
        return True
