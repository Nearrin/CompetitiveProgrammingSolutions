class Solution:
    def rotateGrid(self, a: List[List[int]], k: int) -> List[List[int]]:
        n=len(a)
        m=len(a[0])
        t=min(n//2,m//2)
        for i in range(t):
            tmp=[]
            for j in range(1,n-2*i):
                tmp.append(a[i+j][i])
            for j in range(1,m-2*i):
                tmp.append(a[i+n-2*i-1][i+j])
            for j in range(1,n-2*i):
                tmp.append(a[i+n-2*i-1-j][i+m-2*i-1])
            for j in range(1,m-2*i):
                tmp.append(a[i][i+m-2*i-1-j])
            tmp2=[]
            for j in range(len(tmp)):
                tmp2.append(tmp[((j-k)%len(tmp)+len(tmp))%len(tmp)])
            tmp=tmp2[::-1]
            for j in range(1,n-2*i):
                (a[i+j][i])=tmp.pop()
            for j in range(1,m-2*i):
                (a[i+n-2*i-1][i+j])=tmp.pop();
            for j in range(1,n-2*i):
                (a[i+n-2*i-1-j][i+m-2*i-1])=tmp.pop();
            for j in range(1,m-2*i):
                (a[i][i+m-2*i-1-j])=tmp.pop()
        return a
