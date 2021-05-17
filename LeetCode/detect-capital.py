class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        c1=[chr(ord('A')+i)for i in range(26)]
        c2=[chr(ord('a')+i)for i in range(26)]
        if all(v in c1 for v in word) or all(v in c2 for v in word):
            return True
        if word[0] in c1 and all(v in c2 for v in word[1:]):
            return True
        return False
