def check(c,s):
    from collections import defaultdict
    cnt=defaultdict(int)
    for v in s:
        cnt[v]+=1
    if cnt[c]==0:
        return False
    for v in s:
        if v==c:
            return True
        if cnt[v]==1:
            return False
        cnt[v]-=1#忘了这句话跪了TAT
def cut(c,s):
    i=0
    while s[i]!=c:
        i+=1
    return [t for t in s[i+1:] if t!=c]
class Solution:
    # we decide each letter from right to left
    def removeDuplicateLetters_slow_but_ac(self, s: str) -> str:
        ans='' # be sure to use += instead of = + or it will be n^2
        vis=set()
        while s:
            for c in [chr(ord('a')+i) for i in range(26)]:
                if c in vis:
                    continue
                if check(c,s):
                    ans+=c
                    s=cut(c,s)
                    vis.add(c)
                    break
        return ans
    #let's do better
    def removeDuplicateLetters(self, s: str) -> str:
        from collections import defaultdict
        p=defaultdict(list)
        for i,c in enumerate(s):
            p[c].append(i)
        for c in p:
            p[c]=p[c][::-1]
        r=''
        while True:
            cands=[c for c in p if p[c]]
            if not cands:
                return r
            for c in sorted(cands):
                if all(p[c][-1]<=p[t][0] for t in cands):
                    this_c=c
                    break
            r+=this_c
            idx=p[this_c][-1]
            p[this_c]=[]
            for c in cands:
                while p[c] and p[c][-1]<idx:
                    p[c].pop(-1)
                    
        
