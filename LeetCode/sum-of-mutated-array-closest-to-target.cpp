#include<algorithm>
#include<iostream>
class Solution {
public:
    int myabs(int a){
        return a>0?a:-a;
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>sum(arr.size());
        sum[0]=arr[0];
        for(int i=1;i<arr.size();++i)
            sum[i]=sum[i-1]+arr[i];
        int j=0;
        int best_v=-1;
        int best_d=(~0u>>1);
        for(int i=0;i<=target;++i){
            while(j<arr.size()&&arr[j]<=i)
                ++j;
            int res=0;
            if(j)
                res+=sum[j-1];
            res+=(arr.size()-j)*i;
            int dis=myabs(res-target);
            if(dis<best_d){
                best_d=dis;
                best_v=i;
            }
        }
        return best_v;
    }
};
