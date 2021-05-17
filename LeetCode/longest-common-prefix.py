class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        lcp=strs[0]
        for s in strs[1:]:
            i=-1
            while i+1<len(lcp) and i+1<len(s) and lcp[i+1]==s[i+1]:
                i+=1
            lcp=lcp[:i+1]
        return lcp
