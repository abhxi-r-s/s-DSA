#include<stdio.h>
void main()
{
    int i,j,n,vi[10],u,v,adj[10][10],min=999,cost=0,e=1;
    printf("Enter the number of edges :");
    scanf("%d",&n);

    printf("enter the adjacency matrix :");
    for(i=0;i<n;i++)
    {
        vi[i]==0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]<min)
            {
                min=adj[i][j];
                u=i;
                v=j;
            }
        }
    }
    cost+=min;
    vi[u]=1;
    vi[v]=1;
    printf("{%d,%d}=%d",u,v,min);

    while(e<n-1)
    { min=999;
        for(i=0;i<n;i++)
        {
            if(vi[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(adj[i][j]<min && vi[j]==0)
                    {
                        min=adj[i][j];
                        u=i;
                        v=j;
                    }
                }

            }
        }
        cost+=min;
        vi[v]=1;
        printf("{%d,%d}=%d",u,v,min);
        e+=1;
    }
    printf("Cost is %d",cost);
}