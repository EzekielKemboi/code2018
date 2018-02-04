#include<cstdio>
int main()
{
    int n,i,mark;
    scanf("%d",&n);
    int hash[101]={0};
    int m[100010];
    for(i=0;i<n;i++)
    {
        scanf("%d",&mark);
        hash[mark]++;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",hash[m[i]]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
}
