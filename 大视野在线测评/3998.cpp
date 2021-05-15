#include<cstdio> 
#include<cstring> 
#define N 1000010 
typedef long long ll; 
char s[N];int n,i,j,k,T,K; 
namespace Suffixarray{ 
int S[N],SA[N],rank[N],height[N],sum,pre; 
inline bool leq(int a1,int a2,int b1,int b2){return a1<b1||a1==b1&&a2<=b2;} 
inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3){return a1<b1||a1==b1&&leq(a2,a3,b2,b3);} 
inline void radixPass(int*a,int*b,int*r,int n,int K){ 
  int*c=new int[K+1]; 
  int i,sum,t; 
  for(i=0;i<=K;i++)c[i]=0; 
  for(i=0;i<n;i++)c[r[a[i]]]++; 
  for(i=sum=0;i<=K;i++)t=c[i],c[i]=sum,sum+=t; 
  for(i=0;i<n;i++)b[c[r[a[i]]]++]=a[i]; 
  delete[]c; 
} 
void suffixArray(int*T,int*SA,int n,int K){ 
  int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2; 
  int*R=new int[n02+3];R[n02]=R[n02+1]=R[n02+2]=0; 
  int*SA12=new int[n02+3];SA12[n02]=SA12[n02+1]=SA12[n02+2]=0; 
  int*R0=new int[n0]; 
  int*SA0=new int[n0]; 
  int i,j,name=0,c0=-1,c1=-1,c2=-1,p=0,t=n0-n1,k=0; 
  for(i=j=0;i<n+n0-n1;i++)if(i%3)R[j++]=i; 
  radixPass(R,SA12,T+2,n02,K),radixPass(SA12,R,T+1,n02,K),radixPass(R,SA12,T,n02,K); 
  for(i=0;i<n02;i++){ 
    if(T[SA12[i]]!=c0||T[SA12[i]+1]!=c1||T[SA12[i]+2]!=c2)name++,c0=T[SA12[i]],c1=T[SA12[i]+1],c2=T[SA12[i]+2]; 
    if(SA12[i]%3==1)R[SA12[i]/3]=name;else R[SA12[i]/3+n0]=name; 
  } 
  if(name<n02)for(suffixArray(R,SA12,n02,name),i=0;i<n02;i++)R[SA12[i]]=i+1;else for(i=0;i<n02;i++)SA12[R[i]-1]=i; 
  for(i=j=0;i<n02;i++)if(SA12[i]<n0)R0[j++]=3*SA12[i]; 
  for(radixPass(R0,SA0,T,n0,K);k<n;k++){ 
    #define GetI() (SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2) 
    i=GetI(),j=SA0[p]; 
    if(SA12[t]<n0?leq(T[i],R[SA12[t]+n0],T[j],R[j/3]):leq(T[i],T[i+1],R[SA12[t]-n0+1],T[j],T[j+1],R[j/3+n0])){ 
      SA[k]=i; 
      if(++t==n02)for(k++;p<n0;p++,k++)SA[k]=SA0[p]; 
    }else{ 
      SA[k]=j; 
      if(++p==n0)for(k++;t<n02;t++,k++)SA[k]=GetI(); 
    } 
  } 
  delete[]R;delete[]SA12;delete[]SA0;delete[]R0; 
} 
void work(){ 
  for(i=0;i<n;i++)S[i]=s[i]-'a'+1; 
  suffixArray(S,SA,n,26); 
  for(i=0;i<n;i++)rank[SA[i]]=i; 
  for(k=i=0;i<n;i++)if(rank[i]==n-1)k=0; 
  else{ 
    if(k)k--; 
    for(j=SA[rank[i]+1];S[i+k]==S[j+k];k++); 
    height[rank[i]]=k; 
  } 
  for(i=0;i<n;pre=sum,i++){ 
    sum=pre+n-SA[i]; 
    if(i)sum-=height[i-1]; 
    if(sum>=K){ 
      j=K-pre; 
      if(i)j+=height[i-1]; 
      for(k=0;k<j;k++)putchar(s[SA[i]+k]); 
      return; 
    } 
  } 
  puts("-1"); 
} 
} 
namespace Suffixtree{ 
const int inf=1<<25,S=28; 
int text[N],root,last,pos,need,remain,acnode,ace,aclen; 
int i,j,k,x,y,q[N],tot,g[N];ll f[N]; 
inline int min(int a,int b){return a<b?a:b;} 
struct node{int st,en,lk,son[S];inline int len(){return min(en,pos)-st;}}tree[N]; 
inline int new_node(int st,int en=inf){return tree[++last].st=st,tree[last].en=en,last;} 
inline int acedge(){return text[ace];} 
inline void addedge(int node){ 
  if(need)tree[need].lk=node; 
  need=node; 
} 
inline bool down(int node){ 
  if(aclen>=tree[node].len())return ace+=tree[node].len(),aclen-=tree[node].len(),acnode=node,1; 
  return 0; 
} 
inline void init(){ 
  need=last=remain=ace=aclen=0; 
  root=acnode=new_node(pos=-1,-1); 
} 
inline void extend(int c){ 
  text[++pos]=c;need=0;remain++; 
  while(remain){ 
    if(!aclen)ace=pos; 
    if(!tree[acnode].son[acedge()])tree[acnode].son[acedge()]=new_node(pos),addedge(acnode); 
    else{ 
      int nxt=tree[acnode].son[acedge()]; 
      if(down(nxt))continue; 
      if(text[tree[nxt].st+aclen]==c){aclen++;addedge(acnode);break;} 
      int split=new_node(tree[nxt].st,tree[nxt].st+aclen); 
      tree[acnode].son[acedge()]=split; 
      tree[split].son[c]=new_node(pos); 
      tree[nxt].st+=aclen; 
      tree[split].son[text[tree[nxt].st]]=nxt; 
      addedge(split); 
    } 
    remain--; 
    if(acnode==root&&aclen)aclen--,ace=pos-remain+1; 
    else acnode=tree[acnode].lk?tree[acnode].lk:root; 
  } 
} 
void dfs(int x){ 
  if(tree[x].en==inf)f[x]=g[x]=1; 
  for(int i=0;i<S;i++)if(tree[x].son[i]){ 
    int y=tree[x].son[i]; 
    dfs(y),f[x]+=f[y]+(ll)tree[y].len()*g[y],g[x]+=g[y]; 
  } 
} 
void work(){ 
  init(); 
  for(i=0;i<n;i++)extend(s[i]-'a'+1);extend(27); 
  dfs(x=root); 
  while(1){ 
    if(x!=root&&(ll)tree[x].len()*g[x]>=K){ 
      for(j=1;j<tot;j++)for(k=tree[q[j]].st;k<tree[q[j]].en;k++)putchar(text[k]+'a'-1); 
      for(K=(K-1)/g[x]+1,j=0;j<K;j++)putchar(text[tree[y].st+j]+'a'-1); 
      return; 
    } 
    for(K-=tree[x].len()*g[x],i=0;i<S;i++)if(tree[x].son[i]){ 
      y=tree[x].son[i]; 
      if(f[y]+(ll)(tree[y].len()-1)*g[y]>=K){q[++tot]=x=y;break;}else K-=f[y]+(ll)(tree[y].len()-1)*g[y]; 
    } 
  } 
} 
} 
int main(){ 
  gets(s),scanf("%d%d",&T,&K),n=std::strlen(s); 
  if(K>(ll)n*(n+1)/2)return puts("-1"),0; 
  if(!T)Suffixarray::work();else Suffixtree::work(); 
  return 0; 
}
