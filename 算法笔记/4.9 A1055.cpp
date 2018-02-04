#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;           //结构体可以赋值，数组放在全局变量空间就够用了
struct Billionaire
{
    char name[10];
    int age;
    int money;
};
int k[100010],mi[100010],ma[100010];
Billionaire b[100010],v[100010];
bool cmp(Billionaire a,Billionaire b);
int main()
{
    int i,j,n,m,p=0,num=0;
    int ages[210]={0};

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d",b[i].name,&b[i].age,&b[i].money);   //预处理
    }
    sort(b,b+n,cmp);
    for(i=0;i<n;i++)
    {
        ages[b[i].age]++;
        if(ages[b[i].age]<=101)
        {
            v[num++]=b[i];
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&k[i],&mi[i],&ma[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<num;j++)
        {
            if(p==0)
            {
                p++;
                printf("Case #%d:\n",i+1);
            }
            if(v[j].age>=mi[i]&&v[j].age<=ma[i]&&p<=k[i])
            {
                p++;
                printf("%s %d %d\n",v[j].name,v[j].age,v[j].money);
            }
        }
        if(p==1)
            printf("None\n");
        p=0;
    }
}
bool cmp(Billionaire a1,Billionaire a2)
{
    int c=strcmp(a1.name,a2.name);
    if(a1.money!=a2.money)
        return a1.money>a2.money;
    else if(a1.age!=a2.age)
        return a1.age<a2.age;
    else
        return c<0;
}
