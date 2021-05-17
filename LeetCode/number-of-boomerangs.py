class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        dis=lambda x,y:(x[0]-y[0])**2+(x[1]-y[1])**2
        ans=0
        for j in range(len(points)):
            cnt=defaultdict(int)
            for i in range(len(points)):
                if i!=j:
                    cnt[dis(points[i],points[j])]+=1
            for k in range(len(points)):
                if k!=j:
                    ans+=cnt[dis(points[j],points[k])]-1                    
        return ans
