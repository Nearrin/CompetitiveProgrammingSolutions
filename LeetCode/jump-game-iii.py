def dfs(arr,now,vis):
    if now<0 or now>=len(arr):
        return False
    if now in vis:
        return False
    vis.add(now)
    if arr[now]==0:
        return True
    return dfs(arr,now-arr[now],vis) or dfs(arr,now+arr[now],vis)
    
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        vis=set()
        return dfs(arr,start,vis)
        
