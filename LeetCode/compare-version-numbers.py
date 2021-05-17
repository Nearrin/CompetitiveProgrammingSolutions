class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1=map(int,version1.split('.'))
        v2=map(int,version2.split('.'))
        v1=list(v1)
        v2=list(v2)
        #!!!!! for tail zero!!!
        while len(v1)!=1 and v1[-1]==0:
            v1.pop(-1)
        while len(v2)!=1 and v2[-1]==0:
            v2.pop(-1)
        i=0
        j=0
        while i<len(v1) and j<len(v2):
            if v1[i]!=v2[j]:
                return -1 if v1[i]<v2[j] else 1
            i+=1
            j+=1
        if i==len(v1) and j==len(v2):
            return 0
        if i==len(v1):
            return -1;
        return 1
        
