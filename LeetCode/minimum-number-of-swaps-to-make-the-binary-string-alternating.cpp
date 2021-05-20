class Solution {
public:
    int minSwaps(string s) {
        int ans=-1;
        for(int start='0';start<='1';++start){
            char cur=start;
            int bad0=0,bad1=0;
            for(int i=0;i<s.size();++i){
                char t=(cur-'0'+i)%2+'0';
                if(s[i]!=t){
                    if(s[i]=='0')++bad0;
                    else ++bad1;
                }
            }
            if(bad0==bad1){
                if(ans==-1)ans=bad0;
                else ans=min(ans,bad0);
            }
        }
        return ans;
    }
};
