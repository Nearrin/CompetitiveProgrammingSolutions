class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        sort(begin(a),end(a));
        int m=a[(a.size()-1)/2];
        int i=0,j=a.size()-1;
        vector<int>ans;
        while(k--){
            if(abs(a[j]-m)>=abs(a[i]-m))
                ans.push_back(a[j--]);
            else
                ans.push_back(a[i++]);
        }
        return ans;
    }
};
