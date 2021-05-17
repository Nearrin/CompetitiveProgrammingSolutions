class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        f0=None
        f1=None
        pre_a=None
        pre_b=None
        for a,b in zip(A,B):
           # if not f0: 智障错误
            if f0 is None:
                f0=0
                f1=1
            else:
                n_f0=1010
                n_f1=1010
                if pre_a<a and pre_b<b:
                    n_f0=min(n_f0,f0)
                if pre_b<a and pre_a<b:
                    n_f0=min(n_f0,f1)
                if pre_a<a and pre_b<b:
                    n_f1=min(n_f1,f1+1)
                if pre_b<a and pre_a<b:
                    n_f1=min(n_f1,f0+1)
                f0=n_f0
                f1=n_f1
            pre_a=a
            pre_b=b
        return min(f0,f1)
                
        
