class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans=0;
        int cur=1;
        while(n){
            if(n&1){
                ans=cur-ans;
            }
            cur=cur*2+1;
            n/=2;
        }
        return ans;
    }
};
