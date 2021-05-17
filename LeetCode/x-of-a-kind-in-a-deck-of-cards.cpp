class Solution {
public:
    bool hasGroupsSizeX(vector<int>& a) {
        map<int,int>c;
        for(auto v:a)++c[v];
        for(int i=2;i<=a.size();++i){
            int fail=0;
            if(a.size()%i!=0)fail=1;
            if(fail)continue;
            for(auto t:c)if(t.second%i!=0)fail=1;
            if(!fail)return true;
        }
        return false;
    }
};
