class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        a=[]
        b=[]
        for i,w in enumerate(words):
            if w==word1:
                a.append(i)
            if w==word2:
                b.append(i)
        ans=2100000000
        for u in a:
            for v in b:
                ans=min(ans,abs(u-v))
        return ans
