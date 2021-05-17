class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0:
            return []
        a=[[1]]
        for i in range(1,numRows):
            t=[1]
            for i in range(1,len(a[-1])):
                t.append(a[-1][i-1]+a[-1][i])
            t.append(1)
            a.append(t)
        return a
