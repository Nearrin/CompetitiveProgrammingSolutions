class Solution:
    def myAtoi(self, str: str) -> int:
        ans=[]
        for i in range(len(str)):
            try:
                ans.append(int(str[:i+1]))
            except:
                pass
        if not ans:
            return 0
        ans=ans[-1]
        if ans<-2**31:
            ans=-2**31
        if ans>=2**31:
            ans=2**31-1
        return ans
