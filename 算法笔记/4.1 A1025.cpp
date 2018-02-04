#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student
{
    char id[15];
    int group;
    int score;
    int rank;
};
bool cmp(Student a,Student b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else return strcmp(a.id,b.id)<0;
}
int main()
{
    int n,i,k,j,num=0,r;
    Student stu[30010];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].group=i+1;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].rank=1;
        for(j=1;j<k;j++)
        {
            if(stu[num-k+j].score==stu[num-k+j-1].score)
                stu[num-k+j].rank=stu[num-k+j-1].rank;
            else
                stu[num-k+j].rank=j+1;
        }
    }
    sort(stu,stu+num,cmp);
    printf("%d\n",num);
    for(i=0;i<num;i++)
    {
        if(i>0&&stu[i].score!=stu[i-1].score)
            r=i+1;
        if(i==0)
            r=1;
        printf("%s %d %d %d\n",stu[i].id,r,stu[i].group,stu[i].rank);
    }
}
