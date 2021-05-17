class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        vector<int> r(26);int rc=0;
        vector<int> l(26);int lc=0;
        for(char c:s){
            if((++r[c-'a'])==1){
                ++rc;
            }           
        }
        for(char c:s){
            if((--r[c-'a'])==0){
                --rc;
            }
            if((++l[c-'a'])==1){
                ++lc;
            }
            if(lc==rc){
                ++ans;
            }
        }
        return ans;
    }
};
