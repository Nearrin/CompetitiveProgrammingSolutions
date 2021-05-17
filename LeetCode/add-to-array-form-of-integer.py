class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        return [int(v) for v in str(int(''.join(map(str,A)))+K)]
