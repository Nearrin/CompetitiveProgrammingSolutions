class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        ++a.back();
        int c=0;
        for(int i=a.size()-1;i>=0;--i){
            a[i]+=c;
            c=a[i]/10;
            a[i]%=10;
        }
        if(c)a.insert(a.begin(),c);
        return a;
    }
};
