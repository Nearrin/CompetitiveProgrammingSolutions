class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>>e(n+1);
        for(auto t:edges){
            e[t[0]].push_back(t[1]);
            e[t[1]].push_back(t[0]);
        }
        vector<int>ans(n);
        queue<int>q;
        vector<int>dis(n+1),vis(n+1);
        vector<int>inq(n+1);
        for(int mask=1;mask<(1<<n);++mask){
            int cnt=0,root;
            for(int i=0;i<n;++i)if((mask>>i)&1)++cnt,root=i+1,vis[i+1]=0,inq[i+1]=1;else inq[i+1]=0;
            vis[root]=1;
            dis[root]=0;
            q.push(root);
            int vcnt=1;
            while(q.size()){
                int u=q.front();
                q.pop();
                for(auto v:e[u])if(!vis[v]&&inq[v]){
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    ++vcnt;
                    q.push(v);
                }
            }
            //cout<<mask<<" vcnt"<<vcnt<<endl;
            if(vcnt!=cnt)continue;
            for(int i=0;i<n;++i)if((mask>>i)&1){
                vis[i+1]=0;
                if(dis[i+1]>dis[root])root=i+1;
            }
            vis[root]=1;
            dis[root]=0;
            q.push(root);
            while(q.size()){
                int u=q.front();
                q.pop();
                for(auto v:e[u])if(!vis[v]&&inq[v]){
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
            int tans=0;
             for(int i=0;i<n;++i)if((mask>>i)&1){
                tans=max(tans,dis[i+1]);
            }
            //cout<<mask<<" "<<tans<<endl;
            ans[tans]+=1;
        }
        ans.erase(ans.begin());
        return ans;
    }
};
