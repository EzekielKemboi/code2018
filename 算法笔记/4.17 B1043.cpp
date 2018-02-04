#include<cstdio>
#include<cstring>
int main()
{
    char a[10010];
    int i,len;
    int hash[128]={0};
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        hash[a[i]]++;
    }
    while(i--)
    {
        if(hash['P']!=0)
        {
            printf("P");
            hash['P']--;
        }
        if(hash['A']!=0)
        {
            printf("A");
            hash['A']--;
        }
        if(hash['T']!=0)
        {
            printf("T");
            hash['T']--;
        }
        if(hash['e']!=0)
        {
            printf("e");
            hash['e']--;
        }
        if(hash['s']!=0)
        {
            printf("s");
            hash['s']--;
        }
        if(hash['t']!=0)
        {
            printf("t");
            hash['t']--;
        }
    }
}
