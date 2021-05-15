char d1a[]="\
1 4\n\
1111\n\
";
char d1b[]="\
4 1\n\
1\n\
1\n\
1\n\
1\n\
";
char d2a[]="\
2 3\n\
100\n\
111\n\
";
char d2b[]="\
3 2\n\
01\n\
01\n\
11\n\
";
char d2c[]="\
3 2\n\
11\n\
10\n\
10\n\
";
char d2d[]="\
2 3\n\
111\n\
001\n\
";
char d3a[]="\
2 3\n\
001\n\
111\n\
";
char d3b[]="\
3 2\n\
10\n\
10\n\
11\n\
";
char d3c[]="\
2 3\n\
111\n\
100\n\
";
char d3d[]="\
3 2\n\
11\n\
01\n\
01\n\
";
char d4a[]="\
2 2\n\
11\n\
11\n\
";
char d5a[]="\
2 3\n\
011\n\
110\n\
";
char d5b[]="\
3 2\n\
10\n\
11\n\
01\n\
";
char d6a[]="\
2 3\n\
010\n\
111\n\
";
char d6b[]="\
3 2\n\
10\n\
11\n\
10\n\
";
char d6c[]="\
2 3\n\
111\n\
010\n\
";
char d6d[]="\
3 2\n\
01\n\
11\n\
01\n\
";
char d7a[]="\
2 3\n\
110\n\
011\n\
";
char d7b[]="\
3 2\n\
01\n\
11\n\
10\n\
";
#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cstdio>
#include<unistd.h>
using namespace std;
const int NumberOfRows=15,NumberOfColumns=15;
const int FULL =(1<<NumberOfColumns)-1;
struct Board{
    int d[NumberOfRows];
    int d2[NumberOfColumns];
};
Board GetNewBoard(){
    static Board bd;
    for(int i=0;i<NumberOfRows;++i)
        bd.d[i]=0;
    for(int i=0;i<NumberOfColumns;++i)
        bd.d2[i]=0;
    return bd;
}
struct Piece{
    int h,w;
    int d[4];
    int d2[4];
};
vector< vector<Piece> >pieces;
inline Piece GetNewPiece(const string&s){
    static int n,m;
    static stringstream ss;
    ss<<s;
    ss>>n>>m;
    static Piece p;
    p.h=n;
    p.w=m;
    p.d[0]=p.d[1]=p.d[2]=p.d[3]=0;
    p.d2[0]=p.d2[1]=p.d2[2]=p.d2[3]=0;
    for(int i=1;i<=n;++i){
        static string tmp;
        ss>>tmp;
        for(int j=0;j<tmp.size();++j){
            p.d[n-i]+=((tmp[j]-'0')<<j);
            p.d2[j]+=((tmp[j]-'0')<<(n-i));
        }
    }
    return p;
}
void LoadPieces(){
    pieces.resize(7);
    pieces[0].push_back(GetNewPiece(d1a));
    pieces[0].push_back(GetNewPiece(d1b));
    pieces[1].push_back(GetNewPiece(d2a));
    pieces[1].push_back(GetNewPiece(d2b));
    pieces[1].push_back(GetNewPiece(d2c));
    pieces[1].push_back(GetNewPiece(d2d));
    pieces[2].push_back(GetNewPiece(d3a));
    pieces[2].push_back(GetNewPiece(d3b));
    pieces[2].push_back(GetNewPiece(d3c));
    pieces[2].push_back(GetNewPiece(d3d));
    pieces[3].push_back(GetNewPiece(d4a));
    pieces[4].push_back(GetNewPiece(d5a));
    pieces[4].push_back(GetNewPiece(d5b));
    pieces[5].push_back(GetNewPiece(d6a));
    pieces[5].push_back(GetNewPiece(d6b));
    pieces[5].push_back(GetNewPiece(d6c));
    pieces[5].push_back(GetNewPiece(d6d));
    pieces[6].push_back(GetNewPiece(d7a));
    pieces[6].push_back(GetNewPiece(d7b));
}
struct MoveInformation{
    bool gameover;
    int landingheight;
    int rowsremoved;
    int placementrow;
    Board board;
};
int GetPlacementRow(const Board&board,const Piece&piece,int column){
    for(int row=NumberOfRows-piece.h;row>=0;--row){
        for(int i=0;i<piece.h;++i){
               if(board.d[row+i]&(piece.d[i]<<column))
                    return row+1;
        }
    }
    return 0;
}
int pshan[100010][20];
int shan(int x,int k){
    int t1=    (1<<k)-1;
    int t2=(x&t1);
    x>>=1;
    x&=(~t1);
    return x+t2;
}

MoveInformation DoMove(const Board&board,const Piece&piece,int column){
//    ++gldid;
//    if(gldid==298){
//        cout<<"hehe";
//    }
    static int placementrow;
    placementrow=GetPlacementRow(board,piece,column);
    static MoveInformation mi;
    mi.rowsremoved=0;
    mi.board=board;
    if(placementrow+piece.h>NumberOfRows){
        mi.gameover=true;
        return mi;
    }
    for(int i=0;i<piece.h;++i)
            mi.board.d[placementrow+i]+=(piece.d[i]<<column);
    for(int i=0;i<piece.w;++i)
            mi.board.d2[column+i]+=(piece.d2[i]<<placementrow);
    for(int i=piece.h-1;i>=0;--i){
        if(mi.board.d[placementrow+i]==FULL){
            ++mi.rowsremoved;
            for(int k=0;k<NumberOfColumns;++k){
                mi.board.d2[k]=pshan[mi.board.d2[k]][placementrow+i];

            }
            for(int k=placementrow+i;k<NumberOfRows;++k){
                if(k!=NumberOfRows-1)
                    mi.board.d[k]=mi.board.d[k+1];
                else
                    mi.board.d[k]=0;
            }
        }
    }
//    for(int i=0;i<NumberOfRows;++i)
//        if(mi.board.d[i]>=FULL){
//            cout<<gldid<<endl;
//        }
    mi.gameover=false;
    mi.landingheight=placementrow+(piece.h-1)/2;
    mi.placementrow=placementrow;
    return mi;
}
bool HaveFixed=false;
pair<int,int>GetInputPiece(){
    static int t,p;
    if(!scanf("%d%d",&t,&p))
        return make_pair(-1,-1);
    if(t==2){
        static char s[110];
        scanf("%s",s);
        return make_pair(p-1,s[0]-'a');
    }else
        return make_pair(p-1,-1);
}
int fixedpro=0;
pair<int,int>GetRandomPiece(){
    static int t;
    t=rand()%7;
    if(rand()%100<fixedpro)
        return make_pair(t,rand()%pieces[t].size());
    else
        return make_pair(t,-1);
}
int onec[100010];
inline int OneCount(unsigned int x)
{
  x=(x&0x55555555UL)+((x>>1)&0x55555555UL); //1
  x=(x&0x33333333UL)+((x>>2)&0x33333333UL);//2
  x=(x&0x0f0f0f0fUL)+((x>>4)&0x0f0f0f0fUL); //3
  x=(x&0x00ff00ffUL)+((x>>8)&0x00ff00ffUL); //4
  x=(x&0x0000ffffUL)+((x>>16)&0x0000ffffUL);//5
  return x;
}
int prerowtran[100010];vector<int>wellpos[100010];
int wellans[100010][20];
int lg2[100010];
void precalc(){
    lg2[0]=-1;
     for(int u=1;u<(1<<NumberOfColumns);++u){
         int t=lg2[u-1];
         if(  (1<<(t+1))<=u)
             ++t;
         lg2[u]=t;
     }
    for(int u=0;u<(1<<NumberOfColumns);++u){
        onec[u]=OneCount(u);
        int lst=1;
        for(int j=0;j<NumberOfColumns;++j){
            if( ((u>>j)&1) !=lst){
                ++prerowtran[u];
                lst=((u>>j)&1) ;
            }
        }
        if(lst==0){
            ++prerowtran[u];
        }

        for(int k=0;k<NumberOfRows;++k)
            pshan[u][k]=shan(u,k);

        for(int i=0;i<NumberOfColumns;++i){
            int left,right;
            if(i==0)left=1;
            else left=     ((u>>(i-1))&1);
            if(i==NumberOfColumns-1)
                right=1;
            else right=  ((u>>(i+1))&1);
            int tis=  ((u>>(i))&1);
            if(tis==0&&left+right==2)
                wellpos[u].push_back(i);
        }
        for(int i=0;i<NumberOfRows;++i){
            //wellans[u][i]=
            int t=lg2[(((1<<i)-1)&u)];
            wellans[u][i]=i-t;
        }
    }
}
int GetRowTransitions(const MoveInformation&mi){
    static int r;
    r=0;
    for(int i=0;i<NumberOfRows;++i){
        r+=prerowtran[mi.board.d[i]];

    }
    return r;
}

int GetColumnTransitions(const MoveInformation&mi){
    static int r,lst;
    r=0;
    lst=FULL;
    for(int i=0;i<NumberOfRows;++i){
        r+=onec[mi.board.d[i]^lst];
        lst=mi.board.d[i];
    }
    r+=onec[mi.board.d[NumberOfRows-1]^(FULL)];
    return r;
}

int GetNumberOfHoles(const MoveInformation&mi){
    int holes=0;
    int row_holes=0;
    int previous_row=mi.board.d[NumberOfRows-1];

    for(int i=NumberOfRows-2;i>=0;--i){
        row_holes=~mi.board.d[i]&(previous_row|row_holes);

        holes+=onec[row_holes];

        previous_row=mi.board.d[i];

    }
    return holes;
}
int GetW2(const MoveInformation&mi){
    static int r;
     r=0;
    for(int i=0;i<NumberOfRows;++i){
        vector<int>&v=wellpos[mi.board.d[i]];
        for(int j=0;j<v.size();++j){
            int p=v[j];
            r+=wellans[mi.board.d2[p]][i];
        }
    }
    return r+1;
}


int GetWellSums(const MoveInformation&mi){
    static int r;
     r=0;
    for(int i=0;i<NumberOfRows;++i){
        vector<int>&v=wellpos[mi.board.d[i]];
        for(int j=0;j<v.size();++j){
            int p=v[j];
            r+=wellans[mi.board.d2[p]][i];
        }
    }
    return r;
}
int GetW(const MoveInformation&mi){
    if(GetW2(mi)!=GetWellSums(mi)){
        cout<<"hehe";
    }
    static int r;
     r=0;
    for(int i=0;i<NumberOfRows;++i){
        vector<int>&v=wellpos[mi.board.d[i]];
        for(int j=0;j<v.size();++j){
            int p=v[j];
            r+=wellans[mi.board.d2[p]][i];
        }
    }
    return r;
}

int T1,T2,T3,T4,T5,T6;
int EvaluteBoard(const MoveInformation&mi){
    return mi.landingheight * -T1 +
          mi.rowsremoved * T2 +
          GetRowTransitions(mi )* -T3 +
          GetColumnTransitions(mi) * -T4 +
          GetNumberOfHoles(mi) * -T5+
            GetWellSums(mi)*-T6;
}
struct Move{
    int r,c;
    int tp;
    char rt;
    Board bd;
    int hx;
};
Move GetBestMove(const Board&board,pair<int,int>piece){
    static Move r;
    r.r=-1;
    r.c=-1;
    r.tp=piece.first;
    r.rt='a';
    r.bd=GetNewBoard();
    int v=-(~0u>>1);
    for(int i=0;i<pieces[piece.first].size();++i){
        if(piece.second!=-1&&piece.second!=i)
            continue;
        Piece&pi=pieces[piece.first][i];
        for(int j=0;j+pi.w<=NumberOfColumns;++j){
            static MoveInformation mi;
            mi=DoMove(board,pi,j);
            if(!mi.gameover){
                int tmp=EvaluteBoard(mi);
                if(tmp>v){
                    v=tmp;
                    r.r=NumberOfRows-mi.placementrow;
                    r.c=j+1;
                    r.tp=piece.first;
                    r.rt=i+'a';
                    r.bd=mi.board;
                    r.hx=mi.rowsremoved;
                }
            }
        }
    }
    return r;
}
void print(Board bd){
  //  system("cls");
    cout<<endl;
    for(int i=NumberOfRows-1;i>=0;--i){
        for(int j=0;j<NumberOfColumns;++j)
            if((bd.d[i]>>j)&1)
                cout<<"1";
            else
                cout<<"0";
        cout<<endl;
    }
    cout<<endl;
}
void print2(Board bd){
  //  system("cls");
    cout<<endl;
    for(int i=NumberOfRows-1;i>=0;--i){
        for(int j=0;j<NumberOfColumns;++j)
            if((bd.d2[j]>>i)&1)
                cout<<"1";
            else
                cout<<"0";
        cout<<endl;
    }
    cout<<endl;
}
void NormalGame(){
    int i=1;
    Board bd=GetNewBoard();
    while(true){
        cout<<"round"<<i++<<endl;
        pair<int,int>pi=GetRandomPiece();
        Move mv=GetBestMove(bd,pi);
        if(mv.r==-1)break;
        bd=mv.bd;
        print(bd);
        print2(bd);
        sleep(1);
    }
}
void InputGame(){
    static Board bd;
    bd=GetNewBoard();
    int i=1;
    double st=double(clock())/CLOCKS_PER_SEC;
    while(true){
        double nt=double(clock())/CLOCKS_PER_SEC;
        if(nt-st>0.5){
             printf("hehe\n");
             fflush(stdout);
            break;
         }
         pair<int,int>pi=GetInputPiece();
         if(pi.first==-1)break;
         static Move mv;
         mv=GetBestMove(bd,pi);
         bd=mv.bd;
         printf("%c %d %d\n",mv.rt,mv.r,mv.c);
         fflush(stdout);
        //print(bd);
    }
     ++i;
}
int CalcGame(){
    int i=1;
    Board bd=GetNewBoard();
    int sc=0;
    while(true){
        pair<int,int>pi=GetRandomPiece();
        Move mv=GetBestMove(bd,pi);
        if(mv.r==-1)break;
        bd=mv.bd;
        ++sc;
        sc+=10*mv.hx*mv.hx;
       // print(bd);
        //sleep(0.5);
    }
    return sc;
}
int MoreCalc(int tun){
    int sc=0;
    for(int i=1;i<=tun;++i)
        sc+=CalcGame();
    return sc/tun;
}










int curbest=-1;
int b1,b2,b3,b4,b5,b6;
struct doge{
    void calc(){
        T1=a[0];
        T2=a[1];
        T3=a[2];
        T4=a[3];
        T5=a[4];
        T6=a[5];
        v=MoreCalc(1000);
        if(v>curbest){
            curbest=v;
            b1=a[0];
            b2=a[1];
            b3=a[2];
            b4=a[3];
            b5=a[4];
            b6=a[5];
            cout<<endl;
            cout<<"best: ";
            cout<<v<<endl;
            cout<<b1<<endl;
            cout<<b2<<endl;
            cout<<b3<<endl;
            cout<<b4<<endl;
            cout<<b5<<endl;
            cout<<b6<<endl;
            cout<<endl;
        }
    }
    vector<int>a;
    int v;
};


int sel(vector<doge>&gs){
    int all=gs.size();
    int sum=0;
    for(int i=0;i<all;++i)
        sum+=gs[i].v;
    int uu=rand()%sum+1;
    sum=0;
    for(int i=0;i<all;++i){
        sum+=gs[i].v;
        if(sum>=uu)
            return i;
    }
}

void yichuan(){
    int all=100;
    int bianyi=20;
    vector<doge>gs;
    for(int i=1;i<=all;++i)
    {
        doge tmp;
        for(int j=1;j<=6;++j)
            tmp.a.push_back(rand()%1000);
        tmp.calc();

        gs.push_back(tmp);
       // cout<<"f"<<i<<endl;
    }
    for(int gn=1;;++gn){
        //cout<<gn<<"hehe"<<endl;

        vector<doge>ndg;
        while(ndg.size()!=all){

            int i=sel(gs),j=sel(gs);
            doge di=gs[i],dj=gs[j];

            int c=rand()%6+1;
            for(int u=c;u<=4;++u)
                swap(di.a[u],dj.a[u]);
            for(int u=0;u<5;++u)
                if(rand()%100+1<=bianyi){
                    di.a[u]+=rand()%50-25;
                    if(di.a[u]>=1000)di.a[u]=1000;
                    if(di.a[u]<0)di.a[u]=0;
                }
            for(int u=0;u<5;++u)
                if(rand()%100+1<=bianyi){
                    dj.a[u]+=rand()%50-25;
                    if(dj.a[u]>=1000)dj.a[u]=1000;
                    if(dj.a[u]<0)dj.a[u]=0;
                }
            ndg.push_back(di);
            ndg.push_back(dj);
        }
        gs=ndg;
        for(int i=0;i<all;++i){
           // cout<<"f"<<i<<endl;
            gs[i].calc();
        }
    }
}






//return mi.landingheight * -4.500158825082766 +
//         mi.rowsremoved * 3.4181268101392694*2 +
//         GetRowTransitions(mi )* -3.2178882868487753 +
//         GetColumnTransitions(mi) * -9.348695305445199 +
//         GetNumberOfHoles(mi) * -7.899265427351652;// +
//45
//68
//32
//93
//79


void yichuan2333(){
    int all=100;
    int bianyi=20;
    vector<doge>gs;
    for(;;)
    {
        doge tmp;
        for(int j=1;j<=5;++j)
            tmp.a.push_back(rand()%1000);
        tmp.calc();

       // cout<<"f"<<i<<endl;
    }
    for(int gn=1;;++gn){
        //cout<<gn<<"hehe"<<endl;

        vector<doge>ndg;
        while(ndg.size()!=all){

            int i=sel(gs),j=sel(gs);
            doge di=gs[i],dj=gs[j];

            int c=rand()%6+1;
            for(int u=c;u<=4;++u)
                swap(di.a[u],dj.a[u]);
            for(int u=0;u<5;++u)
                if(rand()%100+1<=bianyi){
                    di.a[u]+=rand()%50-25;
                    if(di.a[u]>=1000)di.a[u]=1000;
                    if(di.a[u]<0)di.a[u]=0;
                }
            for(int u=0;u<5;++u)
                if(rand()%100+1<=bianyi){
                    dj.a[u]+=rand()%50-25;
                    if(dj.a[u]>=1000)dj.a[u]=1000;
                    if(dj.a[u]<0)dj.a[u]=0;
                }
            ndg.push_back(di);
            ndg.push_back(dj);
        }
        gs=ndg;
        for(int i=0;i<all;++i){
           // cout<<"f"<<i<<endl;
            gs[i].calc();
        }
    }
}






//return mi.landingheight * -4.500158825082766 +
//         mi.rowsremoved * 3.4181268101392694*2 +
//         GetRowTransitions(mi )* -3.2178882868487753 +
//         GetColumnTransitions(mi) * -9.348695305445199 +
//         GetNumberOfHoles(mi) * -7.899265427351652;// +
//45
//68
//32
//93
//79






//标准成绩570
#define Q(x) for(int x=-1;x<=1;++x)
void suiji(){
    while(true){
        doge tmp;
        for(int j=1;j<=6;++j)
            tmp.a.push_back(rand()%1000);
        tmp.calc();
        if(tmp.v+50<curbest)
            continue;
        for(int i=1;i<=4;++i){
        //	cout<<i<<endl;
            int b1=-10,b2,b3,b4,b5,b6;
            int bv=-(~0u>>1);
            doge bd;
            Q(x1)Q(x2)Q(x3)Q(x4)Q(x5)Q(x6){
                doge tmp2=tmp;
                tmp2.a[0]+=x1*10;
                    tmp2.a[1]+=x2*50;
                    tmp2.a[2]+=x3*50;
                    tmp2.a[3]+=x4*50;
                    tmp2.a[4]+=x5*50;
                     tmp2.a[5]+=x6*50;
                tmp2.calc();
                if(bv<tmp2.v){
                    bv=tmp2.v;
                    b1=x1;
                        b2=x2;	b3=x3;	b4=x4;	b5=x5;b6=x6;
                        bd=tmp2;
                }
                if(tmp2.v>tmp.v+10)
                    goto ok;
            }

            ok:if(bv<tmp.v+10 )break;
            tmp=bd;

        }


    }
}
void powerful(){
    while(true){
        doge tmp;
        for(int j=1;j<=6;++j)
            tmp.a.push_back(rand()%1000);
        tmp.calc();
        for(int i=1;i<=10;++i){
            int x1=rand()%26-50;
            int x2=rand()%26-50;
            int x3=rand()%26-50;
            int x4=rand()%26-50;
            int x5=rand()%26-50;
            int x6=rand()%26-50;
            doge tmp2=tmp;
            tmp2.a[0]+=x1;
                tmp2.a[1]+=x2;
                tmp2.a[2]+=x3;
                tmp2.a[3]+=x4;
                tmp2.a[4]+=x5;
                 tmp2.a[5]+=x6;
            tmp2.calc();
            if(tmp2.v>tmp.v)
                tmp=tmp2;
        }
    }
}
//t30 1000 得分3189
//t40 1000 得分1131
//t50 1000 得分603
//t60 1000 得分392
//t70 1000 得分276
int main(){
    LoadPieces();
    precalc();
    srand(time(0));
    fixedpro=70;
    T1=125;
    T2=103;
    T3=62-1;
    T4=40;
    T5=492;
    T6=110;
    //cout<<MoreCalc(1000)<<endl;
    //powerful();
    //cout<<MoreCalc(10000)<<endl;
   // suiji();
    //cout<<MoreCalc(10)<<endl;
    //;
    //NormalGame();
 InputGame();
    return 0;



    //yichuan();


    return 0;
}