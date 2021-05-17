class Solution:
    def jump(self, nums: List[int]) -> int:
        f=[0]*len(nums)
        n=len(nums)
        f[n-1]=0
        q=[n-1]
        for i in range(n-2,-1,-1):
            l=0
            r=len(q)-1
            if q[l]-i<=nums[i]:
                f[i]=f[q[l]]+1
            else:
                while l+1<r:
                    m=(l+r)//2
                    if q[m]-i<=nums[i]:
                        r=m
                    else:
                        l=m
                f[i]=f[q[r]]+1
            while q and f[q[-1]]>=f[i]:
                q.pop(-1)
            q.append(i)
        return f[0]
