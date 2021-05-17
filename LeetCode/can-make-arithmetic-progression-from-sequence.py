class Solution:
    def canMakeArithmeticProgression(self, a: List[int]) -> bool:
        a=sorted(a)
        d=set()
        for i in range(1,len(a)):
            d.add(a[i]-a[i-1])
        return len(d)<=1
