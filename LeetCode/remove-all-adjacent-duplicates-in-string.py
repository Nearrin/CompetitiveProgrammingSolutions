class Solution:
    def removeDuplicates(self, S: str) -> str:
        t=[]
        for v in S:
            if not t or t[-1]!=v:
                t.append(v)
            else:
                t.pop(-1)
        return ''.join(t)
