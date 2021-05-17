class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        t=defaultdict(list)
        for i,v in enumerate(list1):
            t[v].append(i)
        for i,v in enumerate(list2):
            t[v].append(i)
        ans=len(list1)+len(list2)
        for k,v in t.items():
            if len(v)==2:
                ans=min(ans,sum(v))
        tt=[]
        for k,v in t.items():
            if len(v)==2 and sum(v)==ans:
                tt.append(k)
        return tt
