#include<stdio.h>

void main()
{
    int n,c,adj[20][20],v[100];
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter the adjacency matrix");
    for(int i=0;i<n;i++)
    { v[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);

        }
    }
    printf("Topological sorting:");
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        { c=0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]!=0)
                {
                    c=1;
                    break;
                }
            }
            if(c==0)
            {
                v[i]=1;
                printf("%d",i);
                for(int j=0;j<n;j++)
                {
                    adj[i][j]=0;
                    
                }
                i=-1;
            }
            
        }
    }
}