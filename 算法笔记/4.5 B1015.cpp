#include<cstdio>
#include<algorithm>
using namespace std;
struct Student
{
    int number;
    int morality;
    int talent;
    int level;
};
bool cmp(Student a,Student b);
int line1,line2;
int main()
{
    int i,n,admission;
    int level[5]={0};
    Student stu[100010];
    scanf("%d %d %d",&n,&line1,&line2);
    admission=n;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&stu[i].number,&stu[i].morality,&stu[i].talent);
        if(stu[i].morality<line1||stu[i].talent<line1)
        {
            stu[i].level=5;
            admission--;
        }
        else if(stu[i].morality>=line2&&stu[i].talent>=line2)
        {
            stu[i].level=1;
            level[1]++;
        }
        else if(stu[i].morality>=line2&&stu[i].talent<line2)
        {
            stu[i].level=2;
            level[2]++;
        }
        else if(stu[i].morality<line2&&stu[i].talent<line2&&stu[i].morality>=stu[i].talent)
        {
            stu[i].level=3;
            level[3]++;
        }
        else
        {
            stu[i].level=4;
            level[4]++;
        }
    }
    sort(stu,stu+n,cmp);
    printf("%d\n",admission);
    for(i=0;i<admission;i++)
    {
        printf("%d %d %d\n",stu[i].number,stu[i].morality,stu[i].talent);
    }
}
bool cmp(Student a,Student b)
{
    if(a.level!=b.level)
        return a.level<b.level;
    else if(a.morality+a.talent!=b.morality+b.talent)
        return a.morality+a.talent>b.morality+b.talent;
    else if(a.morality!=b.morality)
        return a.morality>b.morality;
    else
        return a.number<b.number;
}
