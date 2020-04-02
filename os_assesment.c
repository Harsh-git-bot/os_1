#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h> 
int main()
{
    int current[5][5];
    int avl[5];
    int maxclaim[5][5];
    int allocation[5]={0, 0, 0, 0, 0};
    int run[5];
    int maxres[5];
    int i, j, exec, res, pro;
    bool safe = false;
    int count=0;
    printf("Enter the number of resources: ");
    scanf("%d", &res);
    printf("Enter the number of processes: ");
    scanf("%d", &pro);
    for (i = 0; i < pro; i++) {
        run[i] = 1;
        count++;
    }
    printf("Enter Claim Vector: ");
    for (i = 0; i < res; i++)
        scanf("%d", &maxres[i]);
    printf("Enter Allocated Resource Table: ");
    for (i = 0; i < pro; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &current[i][j]);
    }
    printf("Enter Maximum Claim table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < res; j++)
            scanf("%d", &maxclaim[i][j]);
    }
    printf("The Claim Vector is: ");
    for (i = 0; i < res; i++)
        printf("%d ", maxres[i]);
    printf("The Allocated Resource Table:\n");
    for (i = 0; i < pro; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", current[i][j]);
        printf("\n");
    }
    printf("The Maximum Claim Table:\n");
    for (i = 0; i < pro; i++) {
        for (j = 0; j < res; j++)
            printf("\t%d", maxclaim[i][j]);
        printf("\n");
    }
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            allocation[j] += current[i][j];
    printf("\nAllocated resources: ");
    for (i = 0; i < res; i++)
        printf("%d ", allocation[i]);
    for (i = 0; i < r; i++)
        avl[i] = maxres[i] - allocation[i];
    printf("\nAvailable resources: ");
    for (i = 0; i < res; i++)
        printf("%d ", avl[i]);
    printf("\n");
    while (count != 0) {
        safe = false;
        for (i = 0; i < pro; i++) {
            if (run[i]) {
                exec=1;
                for (j = 0; j < res; j++) {
                    if (maxclaim[i][j] - current[i][j] > avl[j]) {
                        exec=0;
                        break;
                    }
                }
                if (exec)
                {
                    printf("\nProcess%d is executing.\n", i + 1);
                    run[i]=0;
                    count--;
                    safe=true;
                    for (j=0; j<res; j++)
                        avl[j]+=current[i][j];
                    break;
                }
            }
        }
        if (!safe)
        {
            printf("The processes are in unsafe state.");
            break;
        }
 
        if (safe)
            printf("The process is in safe state.");
        printf("\nAvailable vector: ");
        for (i = 0; i < res; i++)
            printf("%d ", avl[i]);
    }
    return 0;
}
