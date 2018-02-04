#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student
{
    int id;
    char name[10];
    int grade;
};
bool cmp(Student a,Student b);
int m;
int main()
{
    int n,i;
    scanf("%d %d",&n,&m);
    Student stu[100010];
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
    }
    sort(stu,stu+n,cmp);
    for(i=0;i<n;i++)
    {
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    }
}
bool cmp(Student a,Student b)
{
    int k;
    if(m==1)
    {
        return a.id<b.id;
    }
    if(m==2)
    {
        k=strcmp(a.name,b.name);
        if(k!=0)
            return k<0;
        else
            return a.id<b.id;
    }
    if(m==3)
    {
        if(a.grade!=b.grade)
            return a.grade<b.grade;
        else
            return a.id<b.id;
    }
}
