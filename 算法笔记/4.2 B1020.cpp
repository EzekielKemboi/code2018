#include<cstdio>
#include<algorithm>
using namespace std;
#define maxsize 1010
struct Omelet
{
    double stock;
    double totalprice;
    double price;
};
bool cmp(Omelet a,Omelet b);
int main()
{
    int n,i;
    double maxprice=0,need;
    Omelet om[maxsize];
    scanf("%d %lf",&n,&need);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&om[i].stock);
    }
    for(i=0;i<n;i++)
    {
        scanf("%lf",&om[i].totalprice);
        om[i].price=om[i].totalprice/om[i].stock;
    }
    sort(om,om+n,cmp);
    i=0;
    while(need>=om[i].stock&&i<n)
    {
        maxprice+=om[i].totalprice;
        need-=om[i].stock;
        i++;
    }
    if(i!=n)
        maxprice+=om[i].price*need;
    printf("%.2f",maxprice);
}
bool cmp(Omelet a,Omelet b)
{
    return a.price>b.price;
}
