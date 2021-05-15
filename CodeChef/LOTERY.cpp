#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define tst int T;scf("%d",&T);while(T--)
#ifndef EULERS_SIEVE
#define EULERS_SIEVE
#include<bits/stdc++.h>
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
        FastReader&operator>>(char*a){for(ign();isc()?1:(*a=0);)*a++=*p++;return*this;}
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
        FastWriter&operator<<(const char*a){while(*a)p.push_back(*a++);return*this;}
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
namespace CTL{
    using namespace std;
    namespace EulersSieve{
        pair<vector<int>,vector<int> >run(int n){
            vector<int>p,ntp(n+1);ntp[1]=1;
            for(int i=2;i<=n;++i){
                if(!ntp[i])p.push_back(i);
                for(int j=0;j<p.size()&&p[j]*i<=n;++j){
                    ntp[p[j]*i]=1;if(i%p[j]==0)break;}}
            return make_pair(p,ntp);}}}
#endif
int CST=0;
int P=1e9+7;
struct trie{
    struct node{
        node(){
            val=1;
            ch[0]=ch[1]=0;
        }
        node*ch[2];
        int val;
    }*root;
    trie(){
        root=new node;
    }
    void ins(node*x,int p,int v,int dep){

        if(dep==-1){
            x->val=lli(x->val)*v%P;
        }else{
            int d=((p>>dep)&1);
            if(!x->ch[d])x->ch[d]=new node;
            ins(x->ch[d],p,v,dep-1);
            x->val=1;
            if(x->ch[0])x->val=lli(x->val)*x->ch[0]->val%P;
            if(x->ch[1])x->val=lli(x->val)*x->ch[1]->val%P;
        }
    }
    int query(int p){
        node*x=root;
        lli ans=1;
        for(int i=16;i>=0;--i){
            if((p>>i)&1){
                if(x->ch[0])ans=ans*x->ch[0]->val%P;
                if(x->ch[1])x=x->ch[1];
                else return ans;
            }else{
                if(x->ch[0])x=x->ch[0];
                else return ans;
            }
        }
        return ans;
    }
  static  node*merge(node*x,node*y,int dep){
        if(dep==-1){
            node*t=new node;
            t->val=lli(x->val)*y->val%P;
            return t;
        }else{
            node*t=new node;
            lop(i,0,1){
                if(x->ch[i]&&y->ch[i]){
                    t->ch[i]=merge(x->ch[i],y->ch[i],dep-1);
                }else if(x->ch[i])
                    t->ch[i]=x->ch[i];
                else
                    t->ch[i]=y->ch[i];
            }
            t->val=1;
            if(t->ch[0])t->val=lli(t->val)*t->ch[0]->val%P;
            if(t->ch[1])t->val=lli(t->val)*t->ch[1]->val%P;
            return t;
        }
    }

    void ins(int p,int v){
        ins(root,p,v,16);
    }
};
struct pot{
    int p,v;
};

vector<pot> seg[100010*4];
vector<int>sum[100010*4];
struct point{
    int pre,val;
};

void inseg(int x,int l,int r,int i1,int i2,int v){
    vector<pot>&segx=seg[x];
    vector<int>&sumx=sum[x];

   if(l==r){
       pot pt;pt.p=i2;
       pt.v=v;
       segx.push_back(pt);
   }
    if(l!=r){
        int m=((l+r)>>1);
        if(i1<=m)
            inseg(x*2,l,m,i1,i2,v);
        else inseg(x*2+1,m+1,r,i1,i2,v);
    }
}
void merge(trie&a,trie&b,trie&c){
        c.root=trie::merge(a.root,b.root,16);
}
bool cmp(pot a,pot b){
    return a.p<b.p;
}

void build(int x,int l,int r){
    vector<pot>&segx=seg[x];
    vector<int>&sumx=sum[x];
    if(l!=r){
           int m=((l+r)>>1);build(x*2,l,m);build(x*2+1,m+1,r);

           segx.resize(seg[x*2].size()+seg[x*2+1].size());
           merge(seg[x*2].begin(),seg[x*2].end(),seg[x*2+1].begin(),seg[x*2+1].end(),segx.begin(),cmp);
           sumx.resize(segx.size());
           if(sumx.size()){
               sumx[0]=segx[0].v;
               for(int i=1;i<segx.size();++i)
                   sumx[i]=lli(sumx[i-1])*segx[i].v%P;
           }
       //    if(r-l>10000)cout<<l<<" "<<r<<" "<<sumx.size()<<endl;
    //    merge(seg[x*2],seg[x*2+1],segx);
    }else{
        sort(all(segx),cmp);
         sumx.resize(segx.size());
         if(sumx.size()){
             sumx[0]=segx[0].v;
             for(int i=1;i<segx.size();++i)
                 sumx[i]=lli(sumx[i-1])*segx[i].v%P;
         }
    }
}

int qseg(int x,int l,int r,int ql,int qr,int qq){

    if(ql<=l&&qr>=r){
        vector<pot>&segx=seg[x];
        vector<int>&sumx=sum[x];
        if(segx.empty())return 1;
        if(segx[0].p>=qq)return 1;
        if(segx.back().p<qq)return sumx.back();
        pot hehe;hehe.p=qq;
        int pz=lower_bound(segx.begin(),segx.end(),hehe,cmp)-segx.begin();
        return sumx[pz-1];
    }
    lli ans=1;
      int m=((l+r)>>1);
      if(qr>m)ans=qseg(x*2+1,m+1,r,ql,qr,qq);
      if(ql<=m)ans=ans*qseg(x*2,l,m,ql,qr,qq)%P;
      return ans;
}


#define LEN 1000010
//#define LEN 10
#include<unordered_map>
vector<point>pts[100010];
int cnt23;
int cnt2he[100010];
int segmx[100010*4];
void build2(int x,int l,int r){
    return;
    if(l==r)segmx[x]=cnt2he[l];
    else{
           int m=((l+r)>>1);
           build2(x*2,l,m);
           build2(x*2+1,m+1,r);
           segmx[x]=max(segmx[x*2],segmx[x*2+1]);
    }
}
int qu2(int x,int ql,int qr,int l,int r){


    for(int i=17;i>=0;--i){
        if(   ((l-1)>>i)+1<=(r>>i))
            return i;
    }


if(ql<0){
   // cout<<ql<<endl;
}
   return 0;
    if(ql<=l&&qr>=r)
        return segmx[x];
    int ret=0;
    int m=((l+r)>>1);
    if(qr>m)ret=qu2(x*2+1,m+1,r,ql,qr);
    if(ql<=m)ret=max(ret,qu2(x*2,l,m,ql,qr));
    return ret;
}

int main(){
    FastReader reader(stdin);
    FastWriter writer(stdout);
    auto pris=EulersSieve::run(100000).first;
    map<pii,int>mp;
    for(int p:pris){
        for(int i=p;i<=100000;i+=p){
            int j=i;int u=0;
            while(j%p==0){
                ++u; j/=p;
                if(p==2)continue;
                point np;
                np.pre=mp[mkp(p,u)];
                mp[mkp(p,u)]=i;
                np.val=p;
                pts[i].push_back(np);

                //static int cnt;++cnt;
             //  if(cnt%10000==0
              //          )cout<<cnt<<endl;
             //   if(p==2||p==3||p==5)++cnt23;
              //  if(p!=2)
                inseg(1,1,100000,i,np.pre,p);
            }
            if(p==2)
                cnt2he[i]=u;
        }
    }
//    lop(i,1,20){
//        cout<<i<<" ";
//        for(point p:pts[i])
//            ptf("(%d,%d)",p.pre,p.val);
//        cout<<endl;
//    }
    build(1,1,100000);
    build2(1,1,100000);
    //cout<<cnt23<<endl;
   // cout<<CST<<endl;
    lli P=1e9+7;
    int T;
    reader>>T;
    int n1,k1;reader>>n1>>k1;
    int A,B,M;reader>>A>>B>>M;
    static int c[LEN],d[LEN];
    lop(i,2,T)reader>>c[i];
        lop(i,2,T)reader>>d[i];
        unordered_map<lli,int>mmp;
    lop(ttt,1,T){

        int l=n1-k1+1,r=n1;

        int ans=1;
          lli u=(lli(l)<<17)+r;
          if(0){
              ans=mmp[u];
          }else{
        if(r-l+1<=100){
        lop(i,l,r)for(point j:pts[i]){
            if(j.pre<l)ans=lli(ans)*j.val%P;
        }
        }else
            ans=qseg(1,1,100000,l,r,l);
           // mmp[u]=ans;
          }

          int delta2=qu2(1,1,100000,l,r);
          ans=lli(ans)*(1<<delta2)%P;

        writer<<ans<<'\n';
   //     int c,d;scf("%d%d",&c,&d);
        n1=1+(lli(A)*ans+c[ttt+1])%M;
        k1=1+(lli(B)*ans+d[ttt+1])%n1;
    }

    return 0;
}
