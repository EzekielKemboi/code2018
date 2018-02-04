#include<cstdio>
void full(int k,int n);
int hash[11]={0},p[11];
int m=1,j=0;
int main()
{
    int n;
    scanf("%d",&n);
    full(1,n);
    printf("%d\n",j);
}
void full(int k,int n)
{
    int i;
    if(k==n+1)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d",p[i]);
        }
        printf("\n");
        j++;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(hash[i]==0)
            {
                p[m]=i;
                m++;
                hash[i]=1;
                full(k+1,n);
                hash[i]=0;
                m--;
            }
        }
    }
}
