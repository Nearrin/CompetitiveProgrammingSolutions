bool check(const string &s1, const string &s2, const string& s3){
    unordered_map<char,int>cnt;
    for(auto c:s1)++cnt[c];
    for(auto c:s2)++cnt[c];
    for(auto c:s3)--cnt[c];
    for(const auto& tmp:cnt)if(tmp.second!=0)return false;
    return true;
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(!check(s1,s2,s3))return false;
        if(s1.size()==0)return s2==s3;
        if(s2.size()==0)return s1==s3;
        vector<vector<bool>>f(s1.size()+1,vector<bool>(s2.size()+1));
        for(int i=0;i<=s1.size();++i){
            for(int j=0;j<=s2.size();++j){
                if(i==0&&j==0)f[i][j]=true;
                else if(i==0)f[i][j]=f[i][j-1]&&(s2[j-1]==s3[i+j-1]);
                else if(j==0)f[i][j]=f[i-1][j]&&(s1[i-1]==s3[i+j-1]);
                else{
                    f[i][j]=(f[i][j-1]&&(s2[j-1]==s3[i+j-1]))||(f[i-1][j]&&(s1[i-1]==s3[i+j-1]));
                }
            }
        }
        return f.back().back();
    }
};
