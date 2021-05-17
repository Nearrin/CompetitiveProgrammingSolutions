class Solution {
public:
    vector<int> runningSum(vector<int> a) {
        for(int i=0;i<a.size();++i){
            if(i)a[i]+=a[i-1];
        }
        return a;
    }
};
