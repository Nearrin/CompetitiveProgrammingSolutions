class Solution {
public:
    int removePalindromeSub(string s) {
        if(!s.size())return 0;
        int f=0,n=s.size();
        for(int i=0;i<n;++i)if(s[i]!=s[n-i-1])f=1;
        if(f)return 2;
        return 1;
    }
};
