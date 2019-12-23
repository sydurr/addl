#include<stdio.h>
int maxi(int a,int b);
int main()
{
    int i,j,price[50],weight[50],n,w;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&weight[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",&price[i]);
    }
    scanf("%d",&w);
    int K[n+1][w+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=w; j++)
        {
            K[i][j]=0;
        }
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=w; j++)
        {
            if(j==0 || i==0)
            {
                K[i][j]=0;
            }

            else if(j>=weight[i-1])
            {
                int a,b;
                a=K[i-1][j];
                b=price[i-1]+K[i-1][j-weight[i-1]];
                K[i][j]=maxi(a,b);
            }
            else
            {
                K[i][j]=K[i-1][j];
            }
        }
    }
    printf("%d\n",K[n][w]);
    /*for(i=0; i<=n; i++)
    {
        for(j=0; j<=w; j++)
        {
            printf("%d ",K[i][j]);
        }
        printf("\n");
    }*/

}
int maxi(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;

}
