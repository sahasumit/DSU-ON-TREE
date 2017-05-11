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

void dfs(int u,int par,int depth)
{
    vis[u]=1;
    L[u]=depth;
    T[u]=par;

    for(int i=0; i<G[u].size(); i++)
    {


        int v=G[u][i];
        if(v==par)continue;
        dfs(v,u,depth+1);


    }


}

int lca_query(int N, int p, int q) //N=নোড সংখ্যা
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
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







int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    input();
    for(int i=1; i<=node; i++)
        if(vis[i]==0)
            dfs(i,i,0);
    lca_init(node);


    return 0;
}


