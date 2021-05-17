class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        int n=s.size();
        for(int i=0;i<s.size();++i){
            string t;
            for(int j=0;j<s.size();++j){
                t.push_back(s[((j-i*b)%n+n)%n]);
            }
            if(b%2==1){
                            string nt=t;
            for(int j=0;j<10;++j){
                for(int jj=0;jj<10;++jj){
                    for(int k=0;k<n;++k)
                        if(k&1)
                        nt[k]=(t[k]-'0'+j*a)%10+'0';
                        else nt[k]=(t[k]-'0'+jj*a)%10+'0';
                    if(nt<ans)ans=nt;
                }
            }
            }
            else{
                        string nt=t;
            for(int j=0;j<10;++j){
                for(int jj=0;jj<1;++jj){
                    for(int k=0;k<n;++k)
                        if(k&1)
                        nt[k]=(t[k]-'0'+j*a)%10+'0';
                        else nt[k]=(t[k]-'0'+jj*a)%10+'0';
                    if(nt<ans)ans=nt;
                }
            }
            }
        }
        return ans;
    }
};
