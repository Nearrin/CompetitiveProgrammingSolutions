class Solution:
    def reverseVowels(self, s: str) -> str:
        s=[c for c in s]
        a=[i for i in range(len(s)) if s[i] in'aeiouAEIOU']
        for i,j in zip(a,a[::-1]):
            if i<j:
                s[i],s[j]=s[j],s[i]
        return ''.join(s)
