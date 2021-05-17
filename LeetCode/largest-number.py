class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # i guess it's not obvious
        # see proof here: https://leetcode.com/problems/largest-number/discuss/291988/A-Proof-of-the-Concatenation-Comparator's
            -Transtivity
        # also functools.cmp_to_key is good
        from functools import cmp_to_key
        def cmp(a,b):
            t1=str(a)+str(b)
            t2=str(b)+str(a)
            if t1==t2:
                return 0
            return 1 if t1<t2 else -1
        t=''.join(map(str,sorted(nums,key=cmp_to_key(cmp))))   
        t=list(t[::-1])
        # what ??!!!!!!!i didnt see that coming
        while len(t)>1 and t[-1]=='0':
            t.pop(-1)
        return ''.join(t[::-1])
