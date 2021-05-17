# either bst or dc dc is way easier
# 这题双指针看起来好难写。。。。。。当时你当作这两个指针独立的就还好。。。
# 注意开闭区间。。。不然不全

def dc(a,s,l,r,lower,upper):
    # calculate s (sotred prefix sum)
    # calculate rs cross
    if l==r:
        s[l]=a[l]
        return 1 if lower<=a[l]<=upper else 0
    else:
        m=(l+r)//2
        ret=dc(a,s,l,m,lower,upper)+dc(a,s,m+1,r,lower,upper)
        tmp=sum(a[i] for i in range(l,m+1))
        for i in range(m+1,r+1):
            s[i]+=tmp
        #s[pr] be the first  > s[i]-lower
        #s[pl] be the first >= s[i]-upper
        pl=l
        pr=l
        for i in range(m+1,r+1):
            while pl<=m and s[pl]<s[i]-upper:
                pl+=1
            while pr<=m and s[pr]<=s[i]-lower:
                pr+=1
            #s[pl:pr]
            if pl==pr:
                pass
            else:
                if s[pl]<=tmp<=s[pr-1]:#fix 1
                    ret+=pr-pl-1
                else:
                    ret+=pr-pl
            #fix 2
            if lower<=s[i]<=upper:
                ret+=1
        tmp=[]
        p1=l
        p2=m+1
        while p1<=m or p2<=r:
            if p1>m:
                tmp.append(s[p2])
                p2+=1
            elif p2>r:
                tmp.append(s[p1])
                p1+=1
            elif s[p1]<s[p2]:
                tmp.append(s[p1])
                p1+=1
            else:
                tmp.append(s[p2])
                p2+=1
        for i in range(l,r+1):
            s[i]=tmp[i-l]
        return ret
            
            
    
        

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        if not nums:
            return 0 ####f!!!!!!!!!!!!!!!!!!!!!!!!!!you re le yici
        return dc(nums,[None]*len(nums),0,len(nums)-1,lower,upper)
        
