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
#define mx 100007
int node;
vector<int>G[mx];
vector<int>root;
void input()
{
    cin>>node;
    for(int i=1; i<=node; i++)
    {
        int u,v;
        v=i;
        cin>>u;
        if(u)
            G[u].PB(v);
        else
            root.PB(i);
    }
}

int L[mx]; //লেভেল
int P[mx][22]; //স্পার্স টেবিল
int T[mx]; //প্যারেন্ট
int SZ[mx];

void dfs2(int from,int u,int dep)
{
    SZ[u]=1;
    T[u]=from;
    L[u]=dep;
    for(int i=0; i<(int)G[u].size(); i++)
    {
        int v=G[u][i];
        if(v==from) continue;
        dfs2(u,v,dep+1);
        SZ[u]+=SZ[v];
    }
}

int lca_query(int N, int p, int depth) //N=নোড সংখ্যা
{

    for(int i=30; i>=0; i--)
        if(depth>=(1<<i))
        {
            depth-=(1<<i);
            p=P[p][i];
            if(p==-1)break;

        }
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
vector<pair<int,int> >V[mx];
int main()
{
    READ("input.txt");
    //WRITE("output.txt");

    input();
    FOR1(i,node)
    if(SZ[i]==0)
    {
        dfs2(-1,i,0);
    }
    lca_init(node);

    int query;
    cin>>query;
    FOR1(i,query)
    {
        int nn,dep;
        cin>>nn>>dep;
        nn=lca_query(node,nn,dep);
        V[nn].PB(MP(dep,i));

    }


    return 0;
}


