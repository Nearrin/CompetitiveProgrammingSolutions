class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        pos={}
        for i in range(len(arr)):
            pos[arr[i]]=i
        pieces=sorted(pieces,key=lambda x:pos.get(x[0],0))
        now=[]
        for i in pieces:
            now+=i
        return now==arr
