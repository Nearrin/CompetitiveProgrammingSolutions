class Solution:
    def confusingNumber(self, N: int) -> bool:
        if not all(c in '16890' for c in str(N)):
            return False
        a=str(N)
        b=a[::-1]
        for u,v in zip(a,b):
            if not (u=='1' and v=='1' or u=='0' and v=='0' or u=='9' and v=='6' or u=='6' and v=='9' or u=='8' and v=='8'):
                return True
        return False
