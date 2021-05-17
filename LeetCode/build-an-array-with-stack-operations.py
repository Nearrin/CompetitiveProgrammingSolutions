class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans=[]
        cnt=0
        for i in range(1,n+1):
            ans.append("Push")
            if not i in target:
                ans.append("Pop")
            else:
                cnt+=1
                if cnt==len(target):
                    return ans
        return ans
            
