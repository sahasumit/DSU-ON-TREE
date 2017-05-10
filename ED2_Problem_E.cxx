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

#define nln        puts("")                         ///prLLInewline
#define getLLI(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(LLI i=1;i<=n;i++)
#define FOR0(i,n)  for(LLI i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(LLI i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (LLI)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long LLI
#define LLI        long long
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

LLI Set(LLI N,LLI pos)
{
    return N=N | (1<<pos);
}
LLI reset(LLI N,LLI pos)
{
    return N= N & ~(1<<pos);
}
bool check(LLI N,LLI pos)
{
    return (bool)(N & (1<<pos));
}
void CI(LLI &_x)
{
    scanf("%d",&_x);
}

void CO(LLI &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],LLI n)
{
    for(LLI i=0; i<n; i++) cin>>a[i];
}
template<typename T> void prLLIarray(T a[],LLI n)
{
    for(LLI i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const LLI INF=0x7f7f7f7f;

LLI dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
LLI dc8[8]= {0,0,-1,1,1,1,-1,-1};
LLI dr4[4]= {0,0,1,-1};                      ///4 direction move
LLI dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
LLI kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
LLI kn8c[8]= {2,1,-1,-2,-2,-1,1,2};
#define mx 100007
LLI node;
LLI colour[mx];
vector<LLI>G[mx];
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
LLI big[mx],sum=0,maximum=0;
void add(LLI v,LLI p,LLI x)
{

    cnt[colour[v]]+=x;

    if(cnt[colour[v]]>maximum)
        maximum=cnt[colour[v]],sum=colour[v];
    else if(cnt[colour[v]]==maximum)sum+=colour[v];

    for(LLI i=0; i<G[v].size(); i++)
    {

        LLI u=G[v][i];
        if(u!=p&&!big[u])
            add(u,v,x);

    }

}
LLI ans[mx];
void dfs(LLI v,LLI p,bool keep)
{



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
    add(v,p,1);

    ans[v]=sum;

    if(bigchild!=-1)
        big[bigchild]=0;
    if(keep==0)
        add(v,p,-1),sum=0,maximum=0;


}


int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    std::ios::sync_with_stdio(false);
    cin>>node;
    FOR1(i,node)
    {
        cin>>colour[i];
    }
    LLI u,v;
    for(LLI i=1; i<node; i++)
    {
        cin>>u>>v;
        G[u].PB(v);
        G[v].PB(u);
    }

    go(1,1);
    dfs(1,1,0);
    for(LLI i=1;i<=node;i++)
    cout<<ans[i]<<" ";


    return 0;
}

