#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include <utility>
//void PrimMST(vector<pair<int,int>> vt[],int v);
using namespace std;
typedef pair <int, int> ipair;
int addEdge(vector<pair<int,int>> vt[], int u,int v,int w)
{
    vt[u].push_back(make_pair(v,w));
    vt[v].push_back(make_pair(u,w));
}
void PrimMST(vector<pair<int,int>> vt[],int v)
{
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    int src=0;
    vector<int>key(v,100000);
    vector<int>parents(v,-1);
    vector<bool>InMST(v,false);

    key[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        InMST[u]=true;
        for(auto x:vt[u])
        {
            int v=x.first;
            int weight=x.second;
            if(InMST[v]==false && key[v]>weight)
            {
                key[v]=weight;

                pq.push(make_pair(weight,v));
                parents[v]=u;
            }
        }
    }
    for(int i=1;i<v;i++){
        printf("%d %d\n",parents[i],i);
    }

}


int main()
{
    int v,u,w,n,i,e,j;

    cin >> n;
    vector <ipair> vt[n];
        scanf("%d",&e);
        for(j=0; j<e; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(vt,u,v,w);
        }

    /*for(i=0; i<n; i++)
    {
        auto x = vt[i];
        for(auto y:x)
            printf("%d vertex is connected with %d weight is %d\n",i,y.first,y.second);
    }*/
    PrimMST(vt,n);
}
