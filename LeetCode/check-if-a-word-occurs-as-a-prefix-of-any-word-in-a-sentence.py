class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        ans=-1
        for i,w in enumerate(sentence.split()):
            if w.startswith(searchWord):
                ans=i+1
                break
        return ans
