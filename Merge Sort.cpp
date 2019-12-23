#include<stdio.h>
#include<string.h>
#include<math.h>
void mergesort(int A[],int p, int r);
void Merge(int A[],int p,int q,int r);
int main()
{
    int n,l,m,r,A[100],i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }

    l=0,r=n-1;
    mergesort(A,l,r);
    for(j=0; j<n; j++)
    {
        printf("%d ",A[j]);
    }
    return 0;
}
void mergesort(int A[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
void Merge(int A[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2],i,j,k;
    for(i=0; i<n1; i++)
    {
        L[i]=A[p+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    for(k=p; k<r; k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];

        }

    }
}
