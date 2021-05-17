class Solution {
public:
    double average(vector<int>& a) {
        sort(begin(a),end(a));
        double s=0;
        for(int i=1;i+1<a.size();++i)s+=a[i];
        return s/(a.size()-2);
    }
};
