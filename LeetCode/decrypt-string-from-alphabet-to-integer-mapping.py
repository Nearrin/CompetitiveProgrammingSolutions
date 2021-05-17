class Solution:
    def freqAlphabets(self, s: str) -> str:
        ans=[]
        i=0
        while i<len(s):
            if i+2<len(s)and s[i+2]=='#':
                ans.append(chr(int(s[i]+s[i+1])-10+ord('j')))
                i+=3
            else:
                ans.append(chr(int(s[i])+ord('a')-1))
                i+=1
        return ''.join(ans)
        
