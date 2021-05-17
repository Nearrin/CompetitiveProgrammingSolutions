class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for(int i=0;i+m<=arr.size();++i){
            int cnt=0;
            for(int j=i;j+m<=arr.size();j+=m){
                int c=1;
                for(int k=0;k<m;++k)if(arr[i+k]!=arr[j+k]){c=0;break;}
                if(c==1)++cnt;
                else break;
            }
            if(cnt>=k)return true;
        }
        return false;
    }
};
