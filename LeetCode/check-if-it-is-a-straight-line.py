class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        def check(x,y):
            return x[0]*y[1]-x[1]*y[0]==0
        a=coordinates
        for i in range(len(a)):
            if i:
                a[i]=(a[i][0]-a[0][0],a[i][1]-a[0][1])
        a=a[1:]
        for i in range(len(a)):
            if not check(a[i],a[0]):
                print(a[i],a[0])
                return False
        return True
                
        
