class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans=[]
        for a in words:
            cnt=0;
            for b in words:
                if a in b and a!=b:
                    cnt+=1
            if cnt!=0:
                ans.append(a)
        return ans
        
