#include<cstdio>
#include<cstring>
int main()
{
    char a[1010];
    gets(a);    //scanf�����ո��ֹͣ�ˣ�gets���Զ�ȡһ�С�
    int i,len;
    char max='a';
    len=strlen(a);
    int hash[27]={0};
    for(i=0;i<len;i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
            a[i]+=32;
        if(a[i]>='a'&&a[i]<='z')
        {
            hash[a[i]-'a']++;
            if(hash[a[i]-'a']>hash[max-'a']||(hash[a[i]-'a']==hash[max-'a']&&a[i]<max))
                max=a[i];
        }
    }
    printf("%c %d\n",max,hash[max-'a']);
}
