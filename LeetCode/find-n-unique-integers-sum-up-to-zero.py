class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n%2==0:
            return [i-n//2 if i<n//2 else i-n//2+1for i in range(n)]
        else:
            return [0]+self.sumZero(n-1)
        
        
