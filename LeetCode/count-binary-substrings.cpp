class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        for(int i=1;i<s.size();++i)
            if(s[i]!=s[i-1]){
                int d=1;
                ++ans;
                while(i-1-d>=0&&s[i-1-d]==s[i-1]&&i+d<s.size()&&s[i+d]==s[i])++d,++ans;
            }
        return ans;
    }
};
