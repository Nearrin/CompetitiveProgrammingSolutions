class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        s,c,a=0,defaultdict(int),0
        c[0]=1
        for v in A:
            s+=v
            a+=c[s-S]
            c[s]+=1
        return a
            
