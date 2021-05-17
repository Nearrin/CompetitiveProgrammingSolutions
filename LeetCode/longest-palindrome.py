class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import defaultdict
        cnt=defaultdict(int)
        for v in s:
            cnt[v]+=1
        ans=0
        has_1=0
        for c in cnt:
            if cnt[c]%2==0:
                ans+=cnt[c]
            elif not has_1:
                has_1=1
                ans+=cnt[c]
            else:
                ans+=cnt[c]-1
        return ans
