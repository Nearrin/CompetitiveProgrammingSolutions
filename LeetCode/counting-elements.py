class Solution:
    def countElements(self, arr: List[int]) -> int:
        b=set(arr)
        ant=0
        for v in arr:
            if v+1 in b:
                ant+=1
        return ant
