def f(x):
    return '0' not in str(x)
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n):
            if f(i) and f(n-i):
                return [i,n-i]
        
