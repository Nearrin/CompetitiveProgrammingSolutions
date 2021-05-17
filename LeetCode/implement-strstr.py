class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        parent=[-1]*len(needle)
        for i in range(1,len(needle)):
            p=parent[i-1]
            while p!=-1 and needle[p+1]!=needle[i]:
                p=parent[p]
            if needle[p+1]==needle[i]:
                parent[i]=p+1
        p=-1
        for i,c in enumerate(haystack):
            while p!=-1 and needle[p+1]!=c:
                p=parent[p]
            if needle[p+1]==c:
                p=p+1
            if p+1==len(needle):
                return i-len(needle)+1
        return -1
            
            
        
