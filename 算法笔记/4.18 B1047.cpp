#include<cstdio>
int main()
{
    int n,i,team,member,grade,maxteam=0,maxscore=0;
    scanf("%d",&n);
    int hash[1010]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d-%d %d",&team,&member,&grade);
        hash[team]+=grade;
    }
    for(i=0;i<1001;i++)
    {
        if(hash[i]>maxscore)
        {
            maxteam=i;
            maxscore=hash[i];
        }
    }
    printf("%d %d\n",maxteam,maxscore);
}
