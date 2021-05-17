class Solution:
    def minOperations(self, logs: List[str]) -> int:
        level=0
        for t in logs:
            if t=='./':
                continue
            if t=='../':
                level=max(0,level-1)
            else:
                level+=1
        return level
