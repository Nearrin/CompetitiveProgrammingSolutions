class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        import copy
        #use copy!
        s=copy.deepcopy(matrix)
        m=matrix
        for i in range(len(m)):
            for j in range(len(m[0])):
                #s[i][j]=m[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]
                s[i][j]=m[i][j]
                if i:
                    s[i][j]+=s[i-1][j]
                if j:
                    s[i][j]+=s[i][j-1]
                if i and j:
                    s[i][j]-=s[i-1][j-1]
        self.s=s
        
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        i1=row1
        j1=col1
        i2=row2
        j2=col2
        r=0
        s=self.s
        #r=s[i2][j2]-s[i2][j1-1]-s[i1-1][j2]+s[i1-1][j1-1]
        r=s[i2][j2]
        if j1:
            r-=s[i2][j1-1]
        if i1:
            r-=s[i1-1][j2]
        if i1 and j1:
            r+=s[i1-1][j1-1]
        return r


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
