#include<cstdio>
#include<cstring>
int main()
{
    char s1[1010];
    char s2[1010];
    char hash[128]={0};
    scanf("%s",s1);
    scanf("%s",s2);
    int i,len1,len2,n=0;
    bool flag=false;
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
    {
        hash[s1[i]]++;
    }
    for(i=0;i<len2;i++)
    {
        hash[s2[i]]--;
        if(hash[s2[i]]<0)
        {
            n++;
            flag=true;
        }
    }
    if(flag==false)
        printf("Yes %d\n",len1-len2);
    else
        printf("No %d\n",n);
}
