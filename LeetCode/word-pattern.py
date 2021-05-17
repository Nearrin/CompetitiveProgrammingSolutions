class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        if not pattern and not str:
            return True
        if not pattern or not str:
            return False
        strs=str.split()
        if len(pattern)!=len(strs):
            return False
        mp={}
        mp2={}
        for p,s in zip(pattern,strs):
            if p not in mp:
                mp[p]=s
            elif mp[p]!=s:
                return False
            if s not in mp2:
                mp2[s]=p
            elif mp2[s]!=p:
                return False
        return True
        
