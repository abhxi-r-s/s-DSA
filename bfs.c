#include<stdio.h>
int n,v[20],A[20][20],queue[20],source,front=-1,rear=-1;
int bfs(int node);
void enqueue(int node);
int dequeue();

void main()
{
    printf("Enter the number of nodes :");
    scanf("%d",&n);

    printf("Enter the adjacency matrix :");
    for(int i=0;i<n;i++)
    {   v[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the source node");
    scanf("%d",&source);

    bfs(source);
}
int bfs(int node)
{
    printf("%d",node);
    v[node]=1;
    enqueue(node);

    while(front!=-1)
    {
        node=dequeue();
        for(int i=0;i<n;i++)
        {
            if(A[node][i]==1 && v[i]!=1)
            {
                v[i]=1;
                printf("%d",i);
                enqueue(i);
            }
        }

    }

}
void enqueue(int node)
{
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=node;

}
int dequeue()
{
    int node=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return node;
}