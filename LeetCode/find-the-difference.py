class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        cnt=defaultdict(int)
        for v in s:
            cnt[v]+=1
        for v in t:
            cnt[v]-=1
        for v in cnt:
            if cnt[v]==-1:
                return v
