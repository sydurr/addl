#include<stdio.h>
#include<iostream>
#include<vector>
#include <utility>
//int addEdge(vector<pair<int ,int >> vt[],int u,int v,int w);
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
    int v,u,w;
    scanf("%d%d%d",&u,&v,&w);
    addEdge(vt,u,v,w);
    auto x = vt[0];
    for(auto y:x)

    printf("%d",y.first);

}
