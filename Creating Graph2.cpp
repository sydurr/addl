#include<stdio.h>
#include<iostream>
#include<vector>
#include <utility>
//int addEdge(vector<pair<int,int>> vt[], int u,int v,int w);
using namespace std;
typedef pair <int, int> ipair;
int addEdge(vector<pair<int,int>> vt[], int u,int v,int w)
{
    vt[u].push_back(make_pair(v,w));
    vt[v].push_back(make_pair(u,w));
}

int main()
{
    vector <ipair> vt[9];
    int v,u,w,n,i,e,j;

    cin >> n;
        scanf("%d",&e);
        for(j=0; j<e; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(vt,u,v,w);
        }

    for(i=0; i<n; i++)
    {
        auto x = vt[i];
        for(auto y:x)
            printf("%d vertex is connected with %d weight is %d\n",i,y.first,y.second);
    }
    /*for(auto y:x)
    printf("%d",y.second);
    */
}
