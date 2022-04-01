#include <stdio.h>

// Macro definition
#define MAX 10

// Global variable
int array[MAX][MAX], queue[MAX], visited[MAX];
int n, i, j, front = 0, rear = -1;

// Functin declaration
void bfs(int v);
void dfs(int v);

// Main Function
void main()
{
    int choice, v, connected, flag;
    printf("\nEnter Number of Nodes in Digraph : ");
    scanf("%d", &n);
    printf("\nEnter the Adjacency Matrix : \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    while (1)
    {
        printf("\n\n1.Test for reachability in Digraph using BFS method\n");
        printf("2.Test for connectivity in Digraph using DFS method\n");
        printf("3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the source vertex: ");
            scanf("%d", &v);
            if ((v < 1) || (v > n))
            {
                printf("\nEnter a valid source vertex");
            }
            else
            {
                for (i = 1; i <= n; i++)
                {
                    visited[i] = 0;
                }
                visited[v] = 1;
                bfs(v);
                printf("The reachable nodes from node %d : ", v);
                for (i = 1; i <= n; i++)
                {
                    if (visited[i] && i != v)
                }
                {
                    printf("%d ", i);
                }
            }
            break;
        case 2:
            for (v = 1; v <= n; v++)
            {
                for (i = 1; i <= n; i++)
                {
                    visited[i] = 0;
                }
                dfs(v);
                flag = 0;
                for (i = 1; i <= n; i++)
                {
                    if (visited[i] == 0)
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    connected = 1;
                }
            }

            if (connected == 1)
            {
                printf("\nGraph is connected\n");
            }
            else
            {
                printf("\nGraph is not connected\n");
            }
            break;
        case 3:
            return;
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}

// Fuction for BFS (rechability)
void bfs(int v)
{
    for (i = 1; i <= n; i++)
    {
        if (array[v][i] && !visited[i])
        {
            queue[++rear] = 1;
        }
    }
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}

// Function for DFS (connectivity)
void dfs(int v)
{
    visited[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (array[v][i] && !visited[i])
        {
            printf("\n%d->%d", v, i);
            dfs(i);
        }
    }
}