class Solution {
public:
    bool backspaceCompare(string a, string b) {
        auto walk=[](const string&s,int i){
            for(int d=0;i!=-1;--i){
                if(s[i]=='#')++d;
                else if(--d<0)break;
            }
            return i;
        };
        int u=a.size(),v=b.size();
        while(true){
            u=walk(a,u-1),v=walk(b,v-1);
            if(u==-1&&v==-1)
                return true;
            if(u==-1||v==-1||a[u]!=b[v])
                return false;
        }
    }
};
