def check(a):
    for i in map(int,str(a)):
        if not i or a%i!=0:
            return False
    return True
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [i for i in range(left,right+1) if check(i)]
