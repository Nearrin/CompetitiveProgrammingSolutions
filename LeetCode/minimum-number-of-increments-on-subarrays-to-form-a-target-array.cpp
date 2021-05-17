class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<pair<int,int>>pos;
        vector<int>pre(target.size()+1),nex(target.size()+1);
        for(int i=0;i<target.size();++i){
            pos.push_back({target[i],i});
            pre[i]=i-1;
            nex[i]=i+1;
            if(nex[i]==target.size())nex[i]=-1;
        }
        int ans=0;
        int last=0;
        int ss=1;
        sort(begin(pos),end(pos));
        for(int i=0;i<pos.size();++i){
            ans+=ss*(pos[i].first-last);
            int j=i;
            for(;j<pos.size()&&pos[j].first==pos[i].first;++j){
                int ii=pos[j].second;
                if(pre[ii]==-1&&nex[ii]==-1){
                    --ss;
                }else if (pre[ii]==-1){
                    pre[nex[ii]]=-1;
                }else if(nex[ii]==-1){
                    nex[pre[ii]]=-1;
                }else{
                    pre[nex[ii]]=-1;nex[pre[ii]]=-1;
                    ++ss;
                }
            }
            --j;
            //cout<<i<<" "<<j<<endl;
            i=j;
            last=pos[i].first;
        }
        return ans;
    }
};
