class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        vector<int>s,d;
        for(int i=a.size()-1;i>=0;--i){
            while(s.size()&&a[s.back()]<=a[i])
                s.pop_back();
            d.push_back(s.size()?s.back()-i:0);
            s.push_back(i);
        }
        reverse(begin(d),end(d));
        return d;
    }
};
