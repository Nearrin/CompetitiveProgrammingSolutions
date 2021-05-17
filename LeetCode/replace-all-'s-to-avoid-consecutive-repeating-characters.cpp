class Solution {
public:
    string modifyString(string s) {
        for(int i=0;i<s.size();++i)        {
            if(s[i]!='?')continue;
            int j=i;
            while(j+1<s.size()&&s[j+1]=='?')++j;
            char s1='!',s2;
            for(int a1='a';a1<='z';++a1)for(int a2='a';a2<='z';++a2){
                if(s1!='!')break;
                if(a1==a2)continue;
                if(i&&a1==s[i-1])continue;
                if(i&&a2==s[i-1])continue;
                if(j+1<s.size()&&a1==s[j+1])continue;
                if(j+1<s.size()&&a2==s[j+1])continue;
                s1=a1;
                s2=a2;
            }
            for(int k=i;k<=j;++k)if(k&1)s[k]=s1;else s[k]=s2;
        }
        return s;
    }
};
