class Solution {
public:
    int distinctEchoSubstrings(string s) {
        const int p=1073741789;
        unordered_set<int>c;
        for(int i=0;i<s.size();++i){
            long long f=0,g=s[i]-'a'+1,d=1;
            for(int j=i,k=i;k<s.size();g=(g*27+s[++k]-96)%p)
                if((k-i+1)%2==0)
                    (f=(f*27+s[j++]-96)%p,d=d*27%p,g==f*(d+1)%p)?(c.insert(g),0):0;
        }
        return c.size();
    }
};
