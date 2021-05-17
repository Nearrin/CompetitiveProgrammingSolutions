class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>a;a.resize(s.size()+1);
        map<char,int>p;
        p['a']=0;
        p['e']=1;
        p['i']=2;
        p['o']=3;
        p['u']=4;
        for(int i=0;i<s.size();++i){
            a[i+1]=a[i];
            if(p.count(s[i]))a[i+1]^=(1<<p[s[i]]);
        }
        map<int,int>m;
        m[0]=0;
        int ans=0;
        for(int i=1;i<=s.size();++i){
            if(m.count(a[i]))ans=max(ans,i-m[a[i]]);
            else m[a[i]]=i;
        }
        return ans;
    }
};
