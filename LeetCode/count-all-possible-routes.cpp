class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        static int f[210][210];
        for(int cf=0;cf<=fuel;++cf){
            for(int p=0;p<locations.size();++p){
                f[cf][p]=(p==finish);
                for(int np=0;np<locations.size();++np){
                    if(p!=np&&cf>=abs(locations[p]-locations[np])){
                        f[cf][p]+=f[cf-abs(locations[p]-locations[np])][np];
                        f[cf][p]%=int(1e9+7);
                    }
                }
            }
        }
        return f[fuel][start];
    }
};
