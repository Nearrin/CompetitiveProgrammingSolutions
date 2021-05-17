#include<algorithm>
int mabs(int x){return x>0?x:-x;}
int dis(int i,int j){
    int px1=i/6,py1=i%6;
    int px2=j/6,py2=j%6;
    return mabs(px1-px2)+mabs(py1-py2);
}

int dfs(vector<vector<int>>&mem,string&word,int level,int pos1,int pos2){
    if(level==word.size())
        return 0;
    if(mem[level][pos1*26+pos2]!=(~0u>>1)){
        return mem[level][pos1*26+pos2];
    }
    int&ans=mem[level][pos1*26+pos2];
    int npos=word[level]-'A';
    ans=min(ans,dfs(mem,word,level+1,npos,pos2)+dis(npos,pos1));
    ans=min(ans,dfs(mem,word,level+1,pos1,npos)+dis(npos,pos2));
    if(level==3){
        //cout<<level<<" "<<char('A'+pos1)<<" "<<char('A'+pos2)<<" "<<ans<<endl;
    }
    return ans;
}
class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<int>>mem(word.size(),vector<int>(26*26,~0u>>1));
        int ans=(~0u>>1);
        for(int i=0;i<26;++i)
            for(int j=0;j<26;++j)
                ans=min(ans,dfs(mem,word,0,i,j));
        return ans;
    }
};
