class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans=0,ans2=-1;
        int cur=0,cur2=0;
        for(int i=0;i<customers.size();++i){
            int v=customers[i];
            cur-=runningCost;
                cur+=boardingCost*min(4,v);
                v-=4;
                cur2+=1;
                if(cur>ans){
                    ans=cur;
                    ans2=cur2;
                }
            if(v>0){
                if(i+1!=customers.size()){
                    customers[i+1]+=v;
                }else customers.push_back(v);
            }
        }
        return ans2;
    }
};
