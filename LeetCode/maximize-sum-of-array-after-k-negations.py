class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        pos=[]
        zer=[]
        neg=[]
        for v in A:
            if v<0:
                neg.append(v)
            elif v>0:
                pos.append(v)
            else:
                zer.append(v)
        if K<=len(neg):
            neg=sorted(neg)
            for i in range(K):
                neg[i]=-neg[i]
            all_v=pos+zer+neg
        else:
            neg=[-v for v in neg]
            K-=len(neg)
            all_v=pos+zer+neg
            all_v=sorted(all_v)
            if K%2==1:
                all_v[0]*=-1
        return sum(all_v)
            
