#include<cstdio>
#include<algorithm>
using namespace std;
struct User
{
    int id;
    int mark[6];
    int total;
    int perfect;
    int rank;
    int print;
};
bool cmp(User a,User b);
int main()
{
    int i,j,n,k,m,subid,subnum,submark,l=0;
    int fullmark[6];
    User u[10010];
    scanf("%d %d %d",&n,&k,&m);
    for(i=0;i<10010;i++)
    {
        for(j=0;j<6;j++)
            u[i].mark[j]=-2;
        u[i].perfect=0;
        u[i].total=0;
        u[i].print=0;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d",&fullmark[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&subid,&subnum,&submark);
        u[subid].id=subid;
        if(u[subid].mark[subnum]!=fullmark[subnum]&&submark==fullmark[subnum])
            u[subid].perfect++;
        if(u[subid].mark[subnum]<submark)
        {
            if(submark==-1)
                u[subid].mark[subnum]=-1;
            else
            {
                u[subid].mark[subnum]=submark;
                u[subid].print=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(u[i].mark[j]!=-2&&u[i].mark[j]!=-1)
                u[i].total+=u[i].mark[j];
        }
    }
    sort(u+1,u+n+1,cmp);
    u[1].rank=1;
    for(i=2;i<=n;i++)
    {
        if(u[i].total==u[i-1].total)
        {
            u[i].rank=u[i-1].rank;
            l++;
        }
        else
        {
            u[i].rank=u[i-1].rank+l+1;
            l=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(u[i].print!=0)
        {
            printf("%d %05d %d ",u[i].rank,u[i].id,u[i].total);
            for(j=1;j<=k;j++)
            {
                if(u[i].mark[j]==-2)
                    printf("-");
                else if(u[i].mark[j]==-1)
                    printf("0");
                else
                    printf("%d",u[i].mark[j]);
                if(j!=k)
                    printf(" ");
            }
            printf("\n");
        }
    }
}
bool cmp(User a,User b)
{
    if(a.total!=b.total)
        return a.total>b.total;
    else if(a.perfect!=b.perfect)
        return a.perfect>b.perfect;
    else
        return a.id<b.id;
}
