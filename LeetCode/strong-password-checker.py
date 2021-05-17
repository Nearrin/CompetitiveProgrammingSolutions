class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        s=[ord(c) for c in s]
        @functools.lru_cache(maxsize=None)
        def gather(s_index,length,last_char_cnt,has_low,has_up,has_digit):
            best=(2147483647//2,0)
            second=(2147483647//2,0)
            for last_char in map(ord,'abAB01'):
                c=dfs(s_index,length,last_char,last_char_cnt,has_low,has_up,has_digit)
                if c<best[0]:
                    second=best
                    best=(c,last_char)
                elif c<second[0]:
                    second=(c,last_char)
            return (best,second)
        @functools.lru_cache(maxsize=None)
        def dfs(s_index,length,last_char,last_char_cnt,has_low,has_up,has_digit):
            if s_index==len(s) and length in range(6,21) and has_low and has_up and has_digit:
                return 0
            c=2147483647//2
            if s_index!=len(s):
                c=min(c,dfs(s_index+1,length,last_char,last_char_cnt,has_low,has_up,has_digit)+1)
            if s_index!=len(s) and length!=20:
                if last_char_cnt!=2 and last_char!=0:
                    c=min(c,dfs(s_index+1,length+1,last_char,last_char_cnt+1,has_low ,has_up,has_digit)+1)
                t=gather(s_index+1,length+1,1,True,has_up ,has_digit)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
                t=gather(s_index+1,length+1,1,has_low,True ,has_digit)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
                t=gather(s_index+1,length+1,1,has_low,has_up ,True)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
                if s[s_index]!=last_char or last_char_cnt!=2:
                    c=min(c,dfs(s_index+1,length+1,s[s_index],1 if s[s_index]!=last_char else (1+last_char_cnt),has_low or 
                        s[s_index] in range(ord('a'),ord('z')+1),has_up or s[s_index]in range(ord('A'),ord('Z')+1),has_digit or 
                        s[s_index]in range(ord('0'),ord('9')+1)))
            if length!=20:
                if last_char_cnt!=2 and last_char!=0:
                    c=min(c,dfs(s_index,length+1,last_char,last_char_cnt+1,has_low ,has_up,has_digit)+1)
                t=gather(s_index,length+1,1,True,has_up ,has_digit)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
                t=gather(s_index,length+1,1,has_low,True ,has_digit)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
                t=gather(s_index,length+1,1,has_low,has_up ,True)
                if t[0][1]==last_char:
                    c=min(c,t[1][0]+1)
                else:
                    c=min(c,t[0][0]+1)
            return c
        return dfs(0,0,0,0,False,False,False)
