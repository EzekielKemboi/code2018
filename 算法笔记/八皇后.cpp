#include<cstdio>
#include<cstdlib>
void count(int k);
int n,num=0;
int hash[11]={0},p[11];
int main()
{
    scanf("%d",&n);
    count(1);
    printf("%d",num);
}
void count(int k)
{
    int i,pre;
    if(k==n+1)
    {
        num++;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(hash[i]==0)
            {
                bool flag=true;
                for(pre=1;pre<k;pre++)
                {
                    if(abs(k-pre)==abs(i-p[pre]))
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                {
                    p[k]=i;
                    hash[i]=1;
                    count(k+1);
                    hash[i]=0;
                }
            }
        }
    }
}
