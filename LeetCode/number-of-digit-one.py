class Solution:
    def countDigitOne(self, n: int) -> int:
        # carefull len_n must >=2 for the remaining code
        if n<10:
            return 1 if n>=1 else 0
        ans=0
        len_n=len(str(n))
        # 1. count 0~10^(len_n-1)-1
        # range(1,len_n) !! or 10**(i-1) will introduce float number
        # carefull about calculation...went wrong once
        ans+=10**(len_n-2)*(len_n-1)
        # 2. count x000..0 ~ x999..9 x in[1,n[0]-1]
        for i in range(1,int(str(n)[0])):
            if i==1:
                ans+=10**(len_n-1)
            ans+=10**(len_n-2)*(len_n-1) # not 10**(len_n-2)*(len_n-2) dacuo le once = =
        # 3. count n[0]000000 to n
        if int(str(n)[0])==1:
            ans+=n-int(str(n)[0])*10**(len_n-1)+1
        # note that leadings zeros are automatically removed
        # things need to be handled if zero is important
        ans+=self.countDigitOne(int(str(n)[1:])) # not inside previous if dacuo le once = =
        return ans
            
        
        
