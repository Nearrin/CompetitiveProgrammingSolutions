class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<int>p[10];
        for(int i=0;i<s.size();++i){
            p[s[i]-'0'].push_back(i);
        }
        for(int i=0;i<10;++i)reverse(begin(p[i]),end(p[i]));
        for(int i=0;i<t.size();++i){
            if(p[t[i]-'0'].empty())return false;
            for(int j=0;j<t[i]-'0';++j)if(p[j].size()&&p[j].back()<p[t[i]-'0'].back())return false;
            p[t[i]-'0'].pop_back();
        }
        return true;
    }
};
