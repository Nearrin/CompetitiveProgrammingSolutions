class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre=-1;
        while(n){
            int t=n&1;
            n>>=1;
            if(t==pre)return false;
            pre=t;
        }
        return true;
    }
};
