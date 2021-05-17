class Solution {
public:
    int minFlips(string target) {
        int cur=0,ans=0;
        for(char c:target){
            if(cur+'0'!=c){
                ++ans;
                cur=1-cur;
            }
        }
        return ans;
    }
};
