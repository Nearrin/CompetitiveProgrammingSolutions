class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp={}
        for i,j in zip(s,t):
            if i not in mp:
                mp[i]=j
            elif mp[i]!=j:
                return False
        return len(mp)==len(set(mp.values()))
        
