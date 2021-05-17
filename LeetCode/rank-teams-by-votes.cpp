bool cmp(const pair<char,vector<int>>&a,const pair<char,vector<int>>&b){
    for(int i=0;i<a.second.size();++i)if(a.second[i]!=b.second[i])return a.second[i]>b.second[i];
    return a.first<b.first;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<char,vector<int>>m;
        for(auto i:votes){
            for(int j=0;j<i.size();++j){
                char c=i[j];
                if(!m.count(c))m[c]=vector<int>(i.size());
                ++m[c][j];
            }
        }
        vector<pair<char,vector<int>>>a;
        for(auto i:m)a.push_back(i);
        sort(a.begin(),a.end(),cmp);
        string ans;
        for(int i=0;i<a.size();++i)ans.push_back(a[i].first);
        return ans;
    }
};
