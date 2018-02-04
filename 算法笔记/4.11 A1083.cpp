#include<cstdio>
#include<algorithm>
using namespace std;
struct Student
{
    char name[12];
    char id[12];
    int grade;
};
bool cmp(Student a,Student b);
int main()
{
    int i,n,grade1,grade2,m=0;
    scanf("%d",&n);
    Student stu[n];
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
    }
    scanf("%d %d",&grade1,&grade2);
    sort(stu,stu+n,cmp);
    for(i=0;i<n;i++)
    {
        if(stu[i].grade>=grade1&&stu[i].grade<=grade2)
        {
            m++;
            printf("%s %s\n",stu[i].name,stu[i].id);
        }
    }
    if(m==0)
        printf("NONE\n");
}
bool cmp(Student a,Student b)
{
    return a.grade>b.grade;
}

