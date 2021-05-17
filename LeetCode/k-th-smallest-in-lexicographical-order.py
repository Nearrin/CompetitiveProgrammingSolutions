def count(n, prefix):
    # carefull 每次遇到这种计数题都要调半天。。。。
    if prefix>n:
        return 0
    ln=len(str(n))
    lp=len(str(prefix))
    #i=0 to ln-lp-1 10**i
    s=(10**(ln-lp)-1)//9
    mi=prefix*10**(ln-lp)
    mx=(1+prefix)*10**(ln-lp)-1
    s+=min(max(n-mi+1,0),mx-mi+1)#!!!yi cuo
    return s

class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        ans=0
        while True:
            #print(ans,k)
            c=[count(n,ans*10+i)for i in range(10)]
            l=0
            r=9
            if ans==0:
                l=1
                c[0]=0#cut tree#!!!yi cuo
            #print(c)
            for i in range(1,10):
                c[i]+=c[i-1]
            #c[r] must >=k
            if c[l]>=k:
                ans=ans*10+l
                if k==1:#!!!yi cuo
                    return ans
                k-=1#!!!yi cuo
            else:
                #c[l]<k
                #c[r]>=k
                while c[l+1]<k:
                    l+=1
                while c[r-1]>=k:
                    r-=1
                ans=ans*10+r
                k-=c[l]
                if k==1:#!!!yi cuo
                    return ans
                k-=1#!!!yi cuo
                    
        
