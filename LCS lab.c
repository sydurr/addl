#include<stdio.h>
#include<string.h>
int lcs_length(char x[],char y[]);
int print_lcs(char x[],int i,int j);
int b[20][20];
int k=0;
char r[10];
int main()
{
    int n,l,m,r,i,z,j;
    char str1[30],str2[30];
    gets(str1);
    gets(str2);

    lcs_length(str1,str2);

    return 0;
}
int lcs_length(char x[],char y[])
{

    int i,j,z,m=strlen(x),n=strlen(y);
    int c[m+1][n+1];
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            c[i][j]=0;
            b[i][j]=0;
        }
    }

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;

            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
    printf("%d\n",c[m][n]);
    print_lcs(x,m,n);
    z=strlen(r);
    for(j=z-1; j>=0; j--)
    {
        printf("%c",r[j]);
    }
}
int print_lcs(char x[],int i,int j)
{
    if(i==0 || j==0)
    {
        return 0;
    }
    if(b[i][j]==1)
    {
        //printf("%c",x[i-1]);
        r[k]=x[i-1];
        k++;
        print_lcs(x,i-1,j-1);

    }
    else if(b[i][j]==2)
    {
        print_lcs(x,i-1,j);
    }
    else if(b[i][j]==3)
    {
        print_lcs(x,i,j-1);
    }
}
