#include<cstdio>
#include<string>

#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class FastStream{
private:
    std::FILE*infile,*outfile;
    std::vector<char>inbuffer,outbuffer;
    char*inpointer,*inend;
    inline void read_file(){
        for(int i=0;;++i){
            inbuffer.resize(inbuffer.size()+(1<<i));
            int t=std::fread(&inbuffer[0]+inbuffer.size()-(1<<i),1,(1<<i),infile);
            if(t!=(1<<i)){
                inpointer=&inbuffer[0];
                inend=inpointer+inbuffer.size()-(1<<i)+t;
                break;
            }
        }
    }
    inline void ignore(){
        while(inpointer!=inend&&std::isspace(*inpointer))
            ++inpointer;
    }
public:
    inline FastStream(std::FILE*_infile,std::FILE*_outfile):
            infile(_infile),outfile(_outfile){
        read_file();
    }
    inline FastStream(std::string _infile,std::string _outfile):
            infile(std::fopen(_infile.c_str(),"r")),outfile(std::fopen(_outfile.c_str(),"w")){
        read_file();
    }
    inline~FastStream(){
        fclose(infile);
        if(!outbuffer.empty())
            std::fwrite(&outbuffer[0],1,outbuffer.size(),outfile);
        fclose(outfile);
    }
    inline FastStream&operator>>(char&a){
        ignore();
        a=*inpointer++;
        return*this;
    }
    inline FastStream&operator>>(char*a){
        ignore();
        while(inpointer!=inend&&!std::isspace(*inpointer))
            *a++=*inpointer++;
        *a=0;
        return*this;
    }
    inline FastStream&operator>>(std::string&a){
        ignore();
        while(inpointer!=inend&&!std::isspace(*inpointer))
            a.push_back(*inpointer++);
        return*this;
    }
    inline FastStream&operator>>(int&a){
        ignore();
        bool f=false;
        if(*inpointer=='-'){
            f=true;
            ++inpointer;
        }
        a=0;
        while(inpointer!=inend&&std::isdigit(*inpointer))
            a=a*10+*inpointer++-'0';
        if(f)
            a=-a;
        return*this;
    }
    inline FastStream&operator>>(long long&a){
        ignore();
        bool f=false;
        if(*inpointer=='-'){
            f=true;
            ++inpointer;
        }
        a=0;
        while(inpointer!=inend&&std::isdigit(*inpointer))
            a=a*10+*inpointer++-'0';
        if(f)
            a=-a;
        return*this;
    }
    template<class VAL>inline void ReadVector(std::vector<VAL>&a,int n=0){
        if(n==0)
            *this>>n;
        for(int i=0;i<n;++i){
            VAL t;
            *this>>t;
            a.push_back(t);
        }
    }
    inline FastStream&operator<<(char a){
        outbuffer.push_back(a);
        return*this;
    }
    inline FastStream&operator<<(const char*a){
        while(*a)
            outbuffer.push_back(*a++);
        return*this;
    }
    inline FastStream&operator<<(const std::string&a){
        for(int i=0;i<a.size();++i)
            outbuffer.push_back(a[i]);
        return*this;
    }
    inline FastStream&operator<<(int a){
        if(a<0){
            outbuffer.push_back('-');
            a=-a;
        }
        static char t[10];
        char*p=t;
        do{
            int b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    inline FastStream&operator<<(unsigned a){
        static char t[10];
        char*p=t;
        do{
            int b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    inline FastStream&operator<<(long long a){
        if(a<0){
            outbuffer.push_back('-');
            a=-a;
        }
        static char t[19];
        char*p=t;
        do{
            long long b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    template<class VAL>inline void WriteVector(const std::vector<VAL>&a,const std::string&b){
        for(int i=0;i<a.size();++i){
            if(i!=0)
                *this<<b;
            *this<<a[i];
        }
    }
};

#include<stack>
const int N=200000;
struct DT{
    int n,r,pr[N+1],ch[N+1][2],rev[N+1],prt[N+1];
    int mi[N+1],yuan[N+1];
    vector<int>to[N+1],tto[N+1];
    int direct(int x){
        if(!pr[x])
            return 2;
        if(x==ch[pr[x]][0])
            return 0;
        if(x==ch[pr[x]][1])
            return 1;
        return 2;
    }
    void down(int x){
        if(rev[x]){
            swap(ch[x][0],ch[x][1]);
            rev[ch[x][0]]^=1;
            rev[ch[x][1]]^=1;
            rev[x]=0;
        }
    }
    void update(int x){
        down(ch[x][0]);
        down(ch[x][1]);
        mi[x]=yuan[x];
        if(ch[x][0])
            mi[x]=min(mi[x],mi[ch[x][0]]);
        if(ch[x][1])
            mi[x]=min(mi[x],mi[ch[x][1]]);
    }
    void setchd(int x,int y,int d){
        ch[x][d]=y;
        pr[y]=x;
        update(x);
    }
    void rotate(int x){
        int y=pr[x],z=pr[y];
        int d1=direct(x),d2=direct(y);
        setchd(y,ch[x][!d1],d1);
        setchd(x,y,!d1);
        if(d2<2)
            setchd(z,x,d2);
        else
            pr[x]=z;
    }
    void release(int x){
        stack<int>stk;
        for(stk.push(x);direct(x)<2;stk.push(pr[x]),x=pr[x]);
        for(;!stk.empty();down(stk.top()),stk.pop());
    }
    void splay(int x){
        release(x);
        while(direct(x)<2){
            int y=pr[x];
            if(direct(y)==2)
                rotate(x);
            else if(direct(x)==direct(y))
                rotate(y),rotate(x);
            else
                rotate(x),rotate(x);
        }
    }
    int access(int x){
        int y=0;
        while(x){
            splay(x);
            setchd(x,y,1);
            y=x;
            x=pr[x];
        }
        return y;
    }
    void evert(int x){
        access(x);
        splay(x);
        rev[x]=1;
    }
    void cut(int x,int y){
        access(y);
        access(x);
        splay(y);
        pr[y]=0;
    }
    void link(int x,int y){
        splay(y);
        pr[y]=x;
    }
    int lca(int x,int y){
        access(x);
        return access(y);
    }
    int query(int x){
        access(x);
        splay(x);
        return mi[x];
    }
    DT(int _n,int _r):
            n(_n),r(_r){
        for(int i=1;i<=n;++i)
            pr[i]=ch[i][0]=ch[i][1]=rev[i]=0;
    }
    void add(int u,int v){
        to[u].push_back(v);
    }
    void build(){
        queue<int>qu;
        static int inq[N+1];
        fill(inq+1,inq+n+1,0);
        fill(prt+1,prt+n+1,0);
        prt[r]=r;
        while(true){
            bool f=false;
            for(int i=1;i<=n;++i)
                if(prt[i]){
                    inq[i]=1;
                    qu.push(i);
                }
            while(!qu.empty()){
                int u=qu.front();
                qu.pop();
                inq[u]=0;
                for(int i=0;i<to[u].size();++i){
                    int v=to[u][i];
                    if(!prt[v]){
                        link(u,v);
                        prt[v]=u;
                        inq[v]=1;
                        qu.push(v);
                        f=true;
                    }else{
                        int w=lca(prt[v],u);
                        if(w!=prt[v]){
                            cut(prt[v],v);
                            link(w,v);
                            prt[v]=w;
                            if(!inq[v]){
                                inq[v]=1;
                                qu.push(v);
                            }
                            f=true;
                        }
                    }
                }
            }
            if(!f)
                break;
        }
        for(int i=1;i<=n;++i)
            if(i!=r&&prt[i])
                tto[prt[i]].push_back(i);
    }
}*dt;
int main(){
    int n,m,r;
    //FastStream fs("plague.in","plague.out");
    FastStream fs(stdin,stdout);
    fs>>n>>m>>r;
    dt=new DT(n,r);
    for(int i=1;i<=m;++i){
        int u,v;
        fs>>u>>v;
        dt->add(u,v);
    }
    for(int i=1;i<=n;++i){
        fs>>dt->yuan[i];
        dt->mi[i]=dt->yuan[i];
    }
    dt->build();
    int q;fs>>q;
    for(int i=1;i<=q;++i){
        int t,w;fs>>t>>w;
        int tmp=-1;
        static int vec[200010];
        vec[0]=0;
        for(int j=1;j<=t;++j){
            int num;
            fs>>num;
            if(dt->prt[num]==0)
                continue;
            vec[++vec[0]]=num;
            if(tmp==-1)
                tmp=num;
            else
                tmp=dt->lca(tmp,num);
        }
        if(vec[0]==0)
            fs<<0<<"\n";
        else {
            for (int j = 1; j <= vec[0]; ++j)
                if (tmp == vec[j])
                    tmp = dt->prt[vec[j]];
            int ty = dt->query(tmp);
            if (ty > w)
                fs << "1\n";
            else
                fs << ty << "\n";
        }

    }
    return 0;
}
