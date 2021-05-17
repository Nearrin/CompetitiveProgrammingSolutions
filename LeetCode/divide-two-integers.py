def fake_mul(a,b):
    if b<0:
        return fake_mul(-a,-b)
    if not b:
        return 0
    t=fake_mul(a,b>>1)
    t=t<<1
    if b&1:
        t=t+a
    return t
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if fake_mul(dividend,divisor)>0:
            sign=1
        else:
            sign=-1
        if dividend<0:
            dividend=-dividend
        if divisor<0:
            divisor=-divisor
        l=0
        r=1
        #Also check f(l) for other problems.
        while fake_mul(r,divisor)<=dividend:
            r*=2
        #Now we have f(l)<=f(x)<f(r).
        while l+1!=r:
            m=int((l+r)//2)
            if fake_mul(m,divisor)<=dividend:
                l=m
            else:
                r=m
        if sign==-1:
            l=-l
        if l not in range(-(1<<31),(1<<31)):
            return (1<<31)-1
        return l
