class Solution:
    def reformatDate(self, date: str) -> str:
        d,m,y=date.split()
        d=d[:-2]
        t=["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        mm=0
        while t[mm]!=m:
            mm+=1
        mm+=1
        return "%s-%02d-%02d"%(y,int(mm),int(d))
