#include<stdio.h>

void main()
{   int n,a[20][20],V[20],min=999,u,v,cost=0,e=0;
    printf("Enter the number of edges :");
    scanf("%d",&n);

    printf("Enter the adjacency matrix :");
    for(int i=0;i<n;i++)
    {
        V[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",a[i][j]);
            if(a[i][j]<min)
            {
                min=a[i][j];
                u=i;
                v=j;
            }
        }
    }
    cost+=min;
    V[u]=1;
    V[v]=1;
    printf("{%d,%d}=%d",u,v,min);
    while(e<n-1)
    { min=999;
        for(int i=0;i<n;i++)
        {
            if(V[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]<min && V[i]==0)
                    {
                        min=a[i][j];
                        u=j;
                    }
                }
            }
        }
        cost+=min;
        V[u]=1;
        printf("{%d,%d}=%d",u,v,min);
        e++;
    }
    printf("Cost is %d",cost);
}