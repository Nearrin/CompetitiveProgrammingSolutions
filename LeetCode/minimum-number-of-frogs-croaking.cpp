class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        map<char,char>p;
        p['c']='k';
        p['r']='c';
        p['o']='r';
        p['a']='o';
        p['k']='a';
        map<char,int>cnt;
        for(auto c:croakOfFrogs){
            auto d=p[c];
            ++cnt[c];
            if(cnt[d])--cnt[d];
            else if(c!='c')return -1;
        }
        int ans=0;
        for(auto t:cnt){
            if(!t.second)continue;
            ans+=t.second;
            if(t.first!='k'){
                return -1;
            }
        }
        return ans;
    }
};
