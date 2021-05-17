class Solution:
    def convertToBase7(self, num: int) -> str:
        if num<0:
            return "-"+self.convertToBase7(-num)
        ans=""
        while num:
            ans+=str(num%7)
            num//=7
        if not ans:
            ans="0"
        return ans[::-1]
