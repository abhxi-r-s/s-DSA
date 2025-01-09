#include<stdio.h>
int adj[20][20],visited[20],n;
void dfs(int val);
void main()
{
    int start;

    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter the adjacency matrix :");
    for(int i=0;i<n;i++)
    {visited[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
printf("Enter the starting node :");
scanf("%d",&start);
printf("DFS");
dfs(start);
}
void dfs(int node)
{
    visited[node]=1;
    printf("%d",node);
    for(int i=0;i<n;i++)
    {
        if(adj[node][i]==1 && visited[i]!=1)
        {
            dfs(i);
        }
    }


}