class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        def work(x):
            return [1-i for i in x[::-1]]
        return list(map(work,A))
        
