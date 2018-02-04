#include<cstdio>
#include<cstring>
int main()
{
    int i,len1,len2;
    char broken[100010];
    char print[100010];
    gets(broken);    //狗逼，第一行可能是空行，用gets可以吸收空行。
    scanf("%s",print);
    len1=strlen(broken);
    bool hash[256]={false};
    for(i=0;i<len1;i++)
    {
        if(broken[i]>='A'&&broken[i]<='Z')
        {
            hash[broken[i]+32]=true;
        }
        else
        {
            hash[broken[i]]=true;
        }
    }
    len2=strlen(print);
    for(i=0;i<len2;i++)
    {
        if(print[i]>='A'&&print[i]<='Z')
        {
            if(hash['+']==false&&hash[print[i]+32]==false)
            {
                printf("%c",print[i]);
            }
        }
        else
        {
            if(hash[print[i]]==false)
            {
                printf("%c",print[i]);
            }
        }
    }
    printf("\n");
}
