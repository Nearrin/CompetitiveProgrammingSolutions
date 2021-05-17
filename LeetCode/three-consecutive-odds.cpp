class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int ans=0;
        for(int i=2;i<a.size();++i){
            if(a[i-2]%2+a[i-1]%2+a[i]%2==3){
                ans=1;
            }
        }return ans;
    }
};
