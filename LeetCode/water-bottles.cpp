class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0,t=0;
        while(numBottles){
            //cout<<numBottles<<" "<<t<<endl;
            ans+=numBottles;
            numBottles+=t;
            t=0;t=numBottles%numExchange;
            numBottles/=numExchange;
            
        }
        return ans;
    }
};
