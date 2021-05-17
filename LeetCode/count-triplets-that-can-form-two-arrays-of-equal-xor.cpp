class Solution {
public:
    int countTriplets(vector<int>& a) {
        int ans=0;
        for(int i=0;i<a.size();++i){
            int t=0;
            for(int j=i;j<a.size();++j){
                t^=a[j];
                if(!t)ans+=j-i;
            }
        }
        return ans;
    }
};
