class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto compress=[](string a){
            vector<pair<char,int>>b;
            for(int i=0;i<a.size();++i){
                int j=i;
                while(j+1<a.size()&&a[j+1]==a[j])
                    ++j;
                b.push_back({a[j],j-i+1});
                i=j;
            }
            return b;
        };
        auto a=compress(name),b=compress(typed);
        if(a.size()!=b.size())return 0;
        for(int i=0;i<a.size();++i)if(a[i].first!=b[i].first||a[i].second>b[i].second)return 0;
        return 1;
    }
};
