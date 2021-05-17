void dfs(int u,vector<int>&vis,vector<int>& leftChild, vector<int>& rightChild,bool&shit){
    if(vis[u]){
        shit=true;
        return;
    }
    vis[u]=1;
    if(leftChild[u]!=-1)
        dfs(leftChild[u],vis,leftChild,rightChild,shit);
    if(rightChild[u]!=-1)
        dfs(rightChild[u],vis,leftChild,rightChild,shit);
}
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>ind(n),vis(n);
        for(int i=0;i<n;++i){
            if(leftChild[i]!=-1)++ind[leftChild[i]];
            if(rightChild[i]!=-1)++ind[rightChild[i]];
        }
        vector<int>root;
        for(int i=0;i<n;++i)if(ind[i]==0)root.push_back(i);
        if(root.size()!=1)
            return false;
        bool shit=false;
        dfs(root[0],vis,leftChild,rightChild,shit);
        for(int i=0;i<n;++i)if(!vis[i])shit=true;
        return !shit;
    }
};
