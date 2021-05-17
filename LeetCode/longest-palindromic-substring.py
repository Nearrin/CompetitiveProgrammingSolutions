class Solution:
    def longestPalindrome(self, s: str) -> str:
        new_s=[]
        for c in s:
            new_s.append(-1)
            new_s.append(c)
        new_s.append(-1)
        ans=[]
        for i in range(len(new_s)):
            j=0
            while i-j-1>=0 and i+j+1<len(new_s) and new_s[i-j-1]==new_s[i+j+1]:
                j+=1
            ans.append(''.join(new_s[i-j+1:i+j+1:2]))
        return max(ans,key=len)
        
