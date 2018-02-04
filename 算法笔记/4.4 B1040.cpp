#include<stdio.h>
#include<cstring>
int main()
{
    int leftp[100010]={0},rightt[100010]={0};
    char pat[100010];
    int len,i,p=0,t=0,ans=0;
    scanf("%s",pat);
    len=strlen(pat);
    for(i=0;i<len;i++)
    {
        leftp[i]=p;
        if(pat[i]=='P')
            p++;
    }
    for(i=len-1;i>=0;i--)
    {
        rightt[i]=t;
        if(pat[i]=='T')
            t++;
        if(pat[i]=='A')
            ans=(ans+leftp[i]*rightt[i])%1000000007;
    }
    printf("%d",ans);
}
