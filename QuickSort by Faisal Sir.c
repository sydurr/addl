#include<stdio.h>
void quicksort(int A[],int p, int r);
int partition(int A[],int p1,int r1);
int main()
{
    int n,l,m,r,A[100],i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
    quicksort(A,0,n-1);
    for(j=0; j<n; j++)
    {
        printf("%d ",A[j]);
    }
    return 0;
}
void quicksort(int A[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int partition(int A[],int p1,int r1)
{
	int x=A[r1];
	int j,i=p1;
	for(j=p1; j<r1; j++)
	{
		if(A[j]<=x)
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
		}
	}
	int temp=A[i];
	A[i]=A[r1];
	A[r1]=temp;
	return i;
}
