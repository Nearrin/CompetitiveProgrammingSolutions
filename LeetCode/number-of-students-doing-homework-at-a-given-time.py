class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        ans=0
        for l,r in zip(startTime,endTime):
            if l<=queryTime and r>=queryTime:
                ans+=1
        return ans
