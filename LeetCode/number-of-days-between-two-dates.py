from datetime import date
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        date1=date(*list(map(int,date1.split('-'))))
        date2=date(*list(map(int,date2.split('-'))))
        return abs((date2-date1).days)
