#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=100000;
template<class COST>struct SPFA{
    int n,src,vis[N],in[N];
    COST di[N];
    vector<int>to[N];
    vector<COST>we[N];
    SPFA(int _n,int _src):
        n(_n),src(_src-1){}
    void add(int u,int v,COST w){
        to[u-1].push_back(v-1);
        we[u-1].push_back(w);
    }
    void run(){
        di[src]=0;
        fill(vis,vis+n,0);
        vis[src]=1;
        fill(in,in+n,0);
        in[src]=1;
        queue<int>qu;
        qu.push(src);
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            in[u]=0;
            for(int i=0;i<to[u].size();++i){
                int v=to[u][i];
                COST w=we[u][i];
                if(!vis[v]||di[u]+w<di[v]){
                    vis[v]=1;
                    di[v]=di[u]+w;
                    //cout<<"upda!"<<v<<" "<<di[v]<<endl;
                    if(!in[v]){
                        in[v]=1;
                        qu.push(v);
                    }
                }
            }
        }
    }
};
#include<map>
#include<utility>
#include<iostream>
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level
        ) {
        int n=friends.size();
        auto spfa=new SPFA<int>(n,id+1);
        for(int i=0;i<n;++i){
            for(auto j:friends[i]){
                spfa->add(i+1,j+1,1);
                spfa->add(j+1,i+1,1);
            }
        }
        spfa->run();
        map<string,int>vds;
        for(int i=0;i<n;++i){
            if(spfa->di[i]==level){
                for(auto s:watchedVideos[i]){
                    if(!vds.count(s))
                        vds[s]=1;
                    else
                        vds[s]+=1;
                }
            }
            //cout<<"find "<<i<<" "<<spfa->di[i]<<endl;
        }
        vector<pair<int,string>>ans;
        for(auto p:vds)
            ans.push_back(make_pair(p.second,p.first));
        sort(ans.begin(),ans.end());
        vector<string>ans2;
        for(auto t:ans)ans2.push_back(t.second);
        return ans2;
    }
};
