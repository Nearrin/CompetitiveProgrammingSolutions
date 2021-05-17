class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        auto a=prices;
        for(int i=0;i<a.size();++i){
            int j=-1;
            for(int k=i+1;k<a.size();++k)if(a[k]<=a[i]){
                j=k;
                break;
            }
            if(j!=-1)a[i]-=a[j];
        }
        return a;
    }
};
