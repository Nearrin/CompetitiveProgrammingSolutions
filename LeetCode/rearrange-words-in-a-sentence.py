class Solution:
    def arrangeWords(self, text: str) -> str:
        a=[(len(j),i,j)for i,j in enumerate(text.split())]
        a=[i[-1].lower()  for i in sorted(a)]
        a=' '.join(a)
        return a[0].upper()+a[1:]
