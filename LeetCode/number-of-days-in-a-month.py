class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        t=[31,28,31,30,31,30,31,31,30,31,30,31]
        if Y%4==0 and Y%100!=0:
            t[1]=29
        if Y%400==0:
            t[1]=29
        return t[M-1]
