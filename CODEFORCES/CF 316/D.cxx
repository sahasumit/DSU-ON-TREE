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
#define mx 500007
int node,query;
string ar;
vector<int>G[mx];
vector<pair<int,int> >V[mx];
void input()
{


    cin>>node;
    cin>>query;
    for(int i=2; i<=node; i++)
    {
        int u,v=i;
        cin>>u;
        G[u].PB(v);

    }
cin>>ar;
ar=" "+ar;

    int v,k;

    for(int i=0; i<query; i++)
    {
        cin>>v>>k;
        V[v].PB(MP(i,k));

    }

}
//#define mx 100007
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

LLI big[mx],sum=0,maximum=0;
int cnt[mx][30];
void add(LLI v,LLI p,LLI depth,LLI x)
{

    cnt[depth][ar[v]-'a']+=  x;
    for(LLI i=0; i<G[v].size(); i++)
    {
        LLI u=G[v][i];
        if(u!=p&&!big[u])
            add(u,v,depth+1,x);
    }

}



int ans[mx];

void dfs(LLI v,LLI p,int depth,bool keep)
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
            dfs(u,v,depth+1,0);
    }


    if(bigchild!=-1)
        dfs(bigchild,v,depth+1,1),big[bigchild]=1;

    add(v,p,depth,1);


    for(int i=0; i<V[v].size(); i++)
    {

       int odd=0;
        for(int j=0; j<26; j++)
        if(cnt[V[v][i].ss][j]%2)
            odd+=1;
//            cout<<"FF "<<V[v][i].ff<<" "<<odd<<" ";
//if(odd<=1)cout<<"Yes\n";
//else cout<<"No\n";
ans[V[v][i].ff]=odd;
//ans[V[v][i].ff]="Yes";
//else
//ans[V[v][i].ff]="No";

    }

//    outputting(v);



    if(bigchild!=-1)
        big[bigchild]=0;
    if(keep==0)
        add(v,p,depth,-1);


}
//map<int,int>M;
//void testing()
//{
//
//    M[1]=2;
//    M[3]=2;
//    M[5]=1;
//    M[6]=0;
//    cout<<M.size()<<"\n";
//    M.erase(6);
//    cout<<M.size()<<"\n";
//}
int main()
{
//    READ("input.txt");
    //WRITE("output.txt");

std::ios::sync_with_stdio(false);
    // testing();
    input();

    go(1,-1);
    dfs(1,1,1,0);


    for(int i=0; i<query; i++)
    {

//        cout<<i<<" :  "<<ans[i]<<"\n";
if(ans[i]>1)cout<<"No\n";
else cout<<"Yes\n";
    }
//    puts("");
    return 0;
}



