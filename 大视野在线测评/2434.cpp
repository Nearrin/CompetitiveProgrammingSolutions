#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
#ifndef FAST_READER_WRITER
#define FAST_READER_WRITER
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct FastReader{
        FILE*f;char*p,*e;vector<char>v;
        FastReader(FILE*_f):f(_f){red();}
        FastReader(string _f):f(fopen(_f.c_str(),"r")){red();}
        ~FastReader(){fclose(f);}
        void red(){
            for(int i=0,t;;++i){
                v.resize(v.size()+(1<<i));
                if((t=fread(&v[0]+v.size()-(1<<i),1,1<<i,f))!=(1<<i)){
                    p=&v[0],e=p+v.size()-(1<<i)+t;break;}}}
        void ign(){while(p!=e&&isspace(*p))++p;}
        int isc(){return p!=e&&!isspace(*p);}
        int isd(){return p!=e&&isdigit(*p);}
        FastReader&operator>>(char&a){ign(),a=*p++;return*this;}
        FastReader&operator>>(char*a){
            for(ign();isc()?1:(*a=0);)*a++=*p++;return*this;}
        FastReader&operator>>(int&a){
            int n=1;if(ign(),a=0,*p=='-')n=-1,++p;
            for(;isd()?1:(a*=n,0);)a=a*10+*p++-'0';
            return*this;}
        FastReader&operator>>(long long&a){
            int n=1;if(ign(),a=0,*p=='-')n=-1,++p;
            for(;isd()?1:(a*=n,0);)a=a*10+*p++-'0';
            return*this;}
        char get(){return*p++;}};
    struct FastWriter{
        FILE*f;vector<char>p;
        FastWriter(FILE*_f):f(_f){}
        FastWriter(string _f):f(fopen(_f.c_str(),"w")){}
        ~FastWriter(){(p.size()?fwrite(&p[0],1,p.size(),f):0),fclose(f);}
        FastWriter&operator<<(char a){p.push_back(a);return*this;}
        FastWriter&operator<<(const char*a){
            while(*a)p.push_back(*a++);return*this;}
        FastWriter&operator<<(int a){
            if(a<0)p.push_back('-'),a=-a;
            static char t[10];char*q=t;
            do{int b=a/10;*q++=a-b*10+'0',a=b;}while(a);
            while(q>t)p.push_back(*--q);
            return*this;}
        FastWriter&operator<<(long long a){
            if(a<0)p.push_back('-'),a=-a;
            static char t[19];char*q=t;
            do{long long b=a/10;*q++=a-b*10+'0',a=b;}while(a);
            while(q>t)p.push_back(*--q);
            return*this;}};}
#endif
int ftrbg[1000010],ftrnx[1000010],fval[1000010],ftrnw;
//vector<int> ftr[100010];
inline void addftr(int u,int v){
    int x=++ftrnw;
    fval[x]=v;
    ftrnx[x]=ftrbg[u];
    ftrbg[u]=x;
}

int tr[100010][26],pr[100010],fa[100010],nw=1;
inline void build(){
    static int qu[1000010];int qf=1,qz=1;
    lp(i,0,25)if(tr[1][i]){
        fa[tr[1][i]]=1,qu[qz++]=tr[1][i];
        addftr(1,tr[1][i]);
       // ftr[1].push_back(tr[1][i]);
    }else tr[1][i]=1;
    while(qf!=qz){
        int u=qu[qf++];
        lp(i,0,25)
            if(!tr[u][i])tr[u][i]=tr[fa[u]][i];
            else{
                fa[tr[u][i]]=tr[fa[u]][i],qu[qz++]=tr[u][i];
                addftr(tr[fa[u]][i],tr[u][i]);
                //ftr[tr[fa[u]][i]].push_back(tr[u][i]);
            }
    }
}
int mp[100010];
char op[100010];
int bg[100010],ed[100010],er=0;
int cnt[100010];
void dfs(int a){
    bg[a]=++er;
    for(int x=ftrbg[a];x;x=ftrnx[x])
        dfs(fval[x]);
    ed[a]=er;
}
int ans[100010];
vector<int> ques[100010],quesid[100010];
void add(int a,int d){
    for(int i=a;i<=nw;i+=i&-i)cnt[i]+=d;
}
int query(int a){
    int r=0;
    for(int i=a;i;i-=i&-i)r+=cnt[i];
    return r;
}
CTL::FastReader rd(stdin);
CTL::FastWriter wt(stdout);
int main(){
    rd>>op;
    for(int k=0,i=0,now=1;op[i];++i){
        if(op[i]=='B')now=pr[now];
        else if(op[i]=='P')mp[++k]=now;
        else{
            if(!tr[now][op[i]-'a']){
                tr[now][op[i]-'a']=++nw;
                pr[nw]=now;
            }
            now=tr[now][op[i]-'a'];
        }
    }
    build();dfs(1);
    int m;rd>>m;
    lp(i,1,m){
        int x,y;rd>>x>>y;
        ques[y].push_back(x);quesid[y].push_back(i);
    }
    for(int k=0,i=0,now=1;op[i];++i){
        if(op[i]=='B')add(bg[now],-1),now=pr[now];
        else if(op[i]=='P'){
            ++k;
            lp(j,0,int(ques[k].size()-1)){
                int v=ques[k][j];
                ans[quesid[k][j]]=query(ed[mp[v]])-query(bg[mp[v]]-1);
            }
        }else{
            now=tr[now][op[i]-'a'];
            add(bg[now],1);
        }
    }
    lp(i,1,m)wt<<ans[i]<<'\n';
    return 0;
}
