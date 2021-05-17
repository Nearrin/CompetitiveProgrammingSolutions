class Solution:
    def reorderSpaces(self, text: str) -> str:
        ns=sum(i==' ' for i in text)
        words=text.split()
        if len(words)==1:
            return words[0]+' '*ns
        tmp=ns//(len(words)-1)
        ans=''
        for i,w in enumerate(words):
            if i:
                ans+=' '*tmp
                ns-=tmp
            ans+=w
        ans+=' '*ns
        return ans
