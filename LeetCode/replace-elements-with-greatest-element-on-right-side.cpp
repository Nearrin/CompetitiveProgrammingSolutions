class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int r=-1;
        for(int i=arr.size()-1;i>=0;--i){
            int t=r;
            if(arr[i]>t)
                t=arr[i];
            arr[i]=r;
            r=t;
        }
        return arr;
    }
};
