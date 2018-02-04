#include<cstdio>
#include<cstring>
int main()
{
    char example[85],actual[85];
    scanf("%s",example);
    scanf("%s",actual);
    bool hash[128]={false};
    int len1=strlen(actual);
    int len2=strlen(example);
    int i;
    for(i=0;i<len1;i++)
    {
        if(actual[i]>='a'&&actual[i]<='z')
        {
            hash[actual[i]-32]=true;
            hash[actual[i]]=true;
        }
        else
            hash[actual[i]]=true;
    }
    for(i=0;i<len2;i++)
    {
        if(example[i]>='a'&&example[i]<='z'&&hash[example[i]-32]==false)
        {
            printf("%c",example[i]-32);
            hash[example[i]-32]=true;
            hash[example[i]]=true;
        }
        else if(example[i]>='A'&&example[i]<='Z'&&hash[example[i]]==false)
        {
            printf("%c",example[i]);
            hash[example[i]]=true;
            hash[example[i]+32]=true;
        }
        else if(hash[example[i]]==false)
        {
            printf("%c",example[i]);
            hash[example[i]]=true;
        }
    }
}
