class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>e(numCourses);
        vector<int>d(e.size());
        for(auto t:prerequisites)
            e[t[1]].push_back(t[0]),
            ++d[t[0]];
        queue<int>q;
        for(int i=0;i<numCourses;++i)
            if(d[i]==0)
                q.push(i);
        vector<int>ans;
        while(q.size()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:e[u])
                if(!--d[v])
                    q.push(v);
        }
        if(ans.size()<e.size())
            ans.clear();
        return ans;
    }
};
