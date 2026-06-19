#include<stdio.h>

void bestfit(int mp[],int p[],int m,int n)
{
    int j=0;

    for(int i=0;i<n;i++)
    {
        if(mp[i]>p[j])
        {
            printf("\n%d fits in %d",p[j],mp[i]);
            mp[i]=mp[i]-p[j++];
            i=i-1;
        }
    }

    for(int i=j;i<m;i++)
        printf("\n%d must wait",p[i]);
}

void sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

int main()
{
    int m,n,mp[20],p[20];

    printf("Number of partitions: ");
    scanf("%d",&n);

    printf("Number of processes: ");
    scanf("%d",&m);

    printf("Enter memory partitions:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&mp[i]);

    printf("Enter process sizes:\n");

    for(int i=0;i<m;i++)
        scanf("%d",&p[i]);

    sort(mp,n);
    sort(p,m);

    bestfit(mp,p,m,n);

    return 0;
}