#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Bill
{
    char name[25];
    int month;
    int day;
    int hour;
    int minute;
    int onoff;
};
bool cmp(Bill a,Bill b);
int last(int day1,int hour1,int minute1,int day2,int hour2,int minute2);
int cost(int day1,int hour1,int minute1,int day2,int hour2,int minute2);
int charge[25];
int main()
{
    int i,j,n,c,needprint=0,next=0,time,total=0;
    double d;
    char off[10];
    Bill b[1010];
    for(i=0;i<24;i++)
    {
        scanf("%d",&charge[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d:%d:%d:%d %s",b[i].name,&b[i].month,&b[i].day,&b[i].hour,&b[i].minute,off);
        if(strcmp(off,"on-line")==0)
            b[i].onoff=1;
        else
            b[i].onoff=0;
    }
    sort(b,b+n,cmp);
    b[n].onoff=1;
    for(i=0;i<n;i++)
    {
        if(strcmp(b[i].name,b[i+1].name)==0)
        {
            if(b[i].onoff==1&&b[i+1].onoff==0)
            {
                needprint=1;
            }
        }
        else
        {
            if(needprint==1)
            {
                printf("%s %02d\n",b[next].name,b[next].month);
                for(j=next;j<i;j++)
                {
                    if(b[j].onoff==1&&b[j+1].onoff==0)
                    {
                        printf("%02d:%02d:%02d %02d:%02d:%02d ",b[j].day,b[j].hour,b[j].minute,b[j+1].day,b[j+1].hour,b[j+1].minute);
                        time=last(b[j].day,b[j].hour,b[j].minute,b[j+1].day,b[j+1].hour,b[j+1].minute);
                        c=cost(b[j].day,b[j].hour,b[j].minute,b[j+1].day,b[j+1].hour,b[j+1].minute);
                        d=(double)c/100.0;
                        total+=c;
                        printf("%d $%.2f\n",time,d);
                    }
                }
                printf("Total amount: $%.2f\n",(double)total/100.0);
                total=0;
            }
            next=i+1;
            needprint=0;
        }
    }
}
bool cmp(Bill a,Bill b)
{
    int s=strcmp(a.name,b.name);
    if(s!=0)
        return s<0;
    else if(a.month!=b.month)
        return a.month<b.month;
    else if(a.day!=b.day)
        return a.day<b.day;
    else if(a.hour!=b.hour)
        return a.hour<b.hour;
    else
        return a.minute<b.minute;
}
int last(int day1,int hour1,int minute1,int day2,int hour2,int minute2)
{
    int count=0;
    while(day1<day2||hour1<hour2||minute1<minute2)
    {
        minute1++;
        count++;
        if(minute1==60)
        {
            minute1=0;
            hour1++;
        }
        if(hour1==24)
        {
            day1++;
            hour1=0;
        }
    }
    return count;
}
int cost(int day1,int hour1,int minute1,int day2,int hour2,int minute2)
{
    int count=0,sum=0;
    while(day1<day2||hour1<hour2||minute1<minute2)
    {
        minute1++;
        count++;
        if(minute1==60)
        {
            minute1=0;
            hour1++;
            sum+=count*charge[hour1-1];
            count=0;
        }
        if(hour1==24)
        {
            day1++;
            hour1=0;
        }
    }
    sum+=count*charge[hour1];
    return sum;
}
/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
15
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line
*/
