#include<cstdio>
#include<algorithm>
using namespace std;
struct Student
{
    int number;
    int score[4];
    int rank[4];
};
int now;
bool cmp(Student a,Student b);
int main()
{
    int n,m,i,j,k,min=2010,minsub=5;
    int check[4000];
    Student stu[2010];
    char sub[5]="CMEA";
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&stu[i].number,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].score[3]=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&check[i]);
    }
    for(now=0;now<4;now++)
    {
        sort(stu,stu+n,cmp);
        stu[0].rank[now]=1;
        for(i=1;i<n;i++)
        {
            if(stu[i].score[now]==stu[i-1].score[now])
                stu[i].rank[now]=stu[i-1].rank[now];
            else
                stu[i].rank[now]=i+1;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(check[i]==stu[j].number)
                break;
        }
        if(j==n)
            printf("N/A\n");
        else
        {
            for(k=2;k>=0;k--)
            {
                if(stu[j].rank[k]<=min)
                {
                    min=stu[j].rank[k];
                    minsub=k;
                }
            }
            if(stu[j].rank[3]<=min)
            {
                min=stu[j].rank[3];
                minsub=3;
            }
            printf("%d %c\n",min,sub[minsub]);
            min=2020;
        }
    }
}
bool cmp(Student a,Student b)
{
    return a.score[now]>b.score[now];
}
