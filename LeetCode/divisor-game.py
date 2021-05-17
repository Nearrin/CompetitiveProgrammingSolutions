f={}
class Solution:
    def divisorGame(self, N: int) -> bool:
        if N in f:
            return f[N]
        if N==1:
            f[N]=False
            return False
        for i in range(1,N):
            if N%i==0:
                if not self.divisorGame(N-i):
                    f[N]=True
                    return True
        f[N]=False
        return False
        
        
