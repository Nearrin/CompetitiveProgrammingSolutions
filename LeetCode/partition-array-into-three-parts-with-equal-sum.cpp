class Solution {
public:
    int sum(vector<int>&a){
        int s=0;
        for(auto v:a)s+=v;
        return s;
    }
    bool canThreePartsEqualSum(vector<int>& a) {
        int t=sum(a)/3;
        if(t*3!=sum(a))return false;
        vector<int>l,m,r;
        int sl=0,sr=0,sm=0;
        int ck=0;
        while(sl!=t||!ck){
            if(!a.size())return false;
            sl+=a.back();
            a.pop_back();
            ck=1;
        }
        ck=0;
        while(sm!=t||!ck){
            if(!a.size())return false;
            sm+=a.back();
            a.pop_back();
            ck=1;
        }
        return a.size();
    }
};
