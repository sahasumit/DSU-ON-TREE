#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

#define nln        puts("")                         ///printnewline
#define getint(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(int i=1;i<=n;i++)
#define FOR0(i,n)  for(int i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(int i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long int
#define LLI        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
void CI(int &_x)
{
    scanf("%d",&_x);
}

void CO(int &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],int n)
{
    for(int i=0; i<n; i++) cin>>a[i];
}
template<typename T> void printarray(T a[],int n)
{
    for(int i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};
#define mx 100005
int node;
vector<int>G[mx];
vector<pair<int,int> >Q;
void input()
{

    cin>>node;
    for(int i=1; i<=node; i++)
    {
        int temp;
        cin>>temp;
        G[temp].PB(i);
    }
    int q;
    cin>>q;
    int a,b;
    FOR0(i,q)
    {

        cin>>a>>b;
        Q.PB(MP(a,b));
    }


}

//lca fuctino

int L[mx]; //লেভেল
int P[mx][22]; //স্পার্স টেবিল
int T[mx]; //প্যারেন্ট
bool vis[mx];

void dfs2(int u,int par,int depth)
{
    vis[u]=1;
    L[u]=depth;
    T[u]=par;

    for(int i=0; i<G[u].size(); i++)
    {


        int v=G[u][i];
        if(v==par)continue;
        dfs2(v,u,depth+1);


    }


}

int lca_query(int N, int p, int depth) //N=নোড সংখ্যা
{

    for(int i=30; i>=0; i--)
        if((1<<i)<=depth)
        {


            p=P[p][i];
            depth-=(1<<i);

        }

//        if(depth>0)return -1;
    return p;


}

void lca_init(int N)
{
    memset (P,-1,sizeof(P)); //শুরুতে সবগুলো ঘরে -১ থাকবে
    int i, j;
    for (i = 1; i <=N; i++)
        P[i][0] = T[i];

    for (j = 1; (1 << j) < N; j++)
        for (i = 1; i <=N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

vector<int>V[mx];

LLI SZ[mx];
void go(LLI u,LLI p)
{


    SZ[u]=1;
    for(LLI i=0; i<G[u].size(); i++)
    {
        LLI v=G[u][i];
        if(p==v)continue;
        go(v,u);
        SZ[u]+=SZ[v];
    }
}


LLI cnt[mx];
LLI big[mx];
void add(LLI v,LLI p,int depth,int x)
{

    cnt[depth]+=x;


    for(LLI i=0; i<G[v].size(); i++)
    {

        LLI u=G[v][i];
        if(u!=p&&!big[u])
            add(u,v,depth+1,x);
    }

}
map<int,int>ans[mx];
bool used[mx];
void dfs(LLI v,LLI p,bool keep)
{


used[v]=1;
    LLI maxi=-1,bigchild=-1;

    for(LLI i=0; i<G[v].size(); i++)
    {
        LLI u=G[v][i];
        if(u!=p&&SZ[u]>maxi)
            maxi=SZ[u],bigchild=u;
    }
    for(LLI i=0; i<G[v].size(); i++)
    {

        LLI u=G[v][i];
        if(u!=p&&u!=bigchild)
            dfs(u,v,0);
    }
    if(bigchild!=-1)
        dfs(bigchild,v,1),big[bigchild]=1;;
    add(v,p,0,1);

    for(int j=0;j<V[v].size();j++){

    int a=v,b=V[v][j];
    ans[a][b]=cnt[b];
    }

//    ans[v]=sum;
//
    if(bigchild!=-1)
        big[bigchild]=0;
    if(keep==0)
        add(v,p,0,-1);


}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    input();
//    memset(T,-1,sizeof T);
    for(int i=1; i<=node; i++)
        if(vis[i]==0)
        {
            dfs2(i,-1,0);
            go(i,-1);
        }

    lca_init(node);
//    int a,b;

    int sz=Q.size();
    for(int i=0; i<sz; i++)
    {

        int a,b;
        a=Q[i].ff,b=Q[i].ss;

//cout<<"FF "<<a<<" "<<b<<" : = "<<lca_query(node,a,b)<<"\n";
        a=lca_query(node,a,b);
        Q[i]=MP(a,b);
        V[a].PB(b);

    }
    //adding dsu
    for(int i=1;i<=node;i++)
    if(used[i]==0)
    {

dfs(i,i,0);

    }
    for(int i=0;i<Q.size();i++){

    int a,b;
    a=Q[i].ff,b=Q[i].ss;
    cout<<ans[a][b]<<"\n";

    }



    return 0;
}


