#include<cstdio>
int main()
{
    int i,j;
    int num[11];
    for(i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=1;i<=10;i++)
    {
        if(num[i]!=0)
        {
            printf("%d",i);
            num[i]--;
            break;
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<num[i];j++)
        {
            printf("%d",i);
        }
    }
}
