#include<stdio.h>

struct process {
    int bt, rbt, tat, wt, id;
} p[50], x[50];

void main() {
    int i,j,k-1, n,netBurst=0,cmp=0;
    int totalTAT = 0, totalWT = 0;

    float avgTAT, avgWT;

    printf("Reading the number of processes... ");
    scanf("%d", &n);

    printf("Reading the burst times of each process... ");
    for(i=0;i<n;i++) {
        printf("PROCESS %d\t->\t", i+1);
        p[i].id = i+1;
        scanf("%d", &p[i].bt);
        p[i].rbt = p[i].bt;
        netBurst += p[i].bt;
    }   

    x[0].tat = 0;
    int qt;
    printf("Reading the time slice... ");
    scanf("%d", &qt);

    while (cmp != netBurst) {
        for (i=0; i<n; i++) {
            if (p[i].rbt != 0) {
                x[k].id = i+1;
                if (p[i].rbt - qt <= 0) {
                    x[k].wt = x[k-1].tat;
                    x[k].bt = p[i].rbt;
                    x[k].tat = x[k].wt + x[k].bt;

                    p[i].rbt = 0;
                    p[i].tat = x[k].tat;
                    p[i].wt = p[i].tat - p[i].bt;

                    cmp = x[k].tat;
                    k++;

                    totalTAT += p[i].tat;
                    totalWT += p[i].wt;
                } else {
                    x[k].wt = x[k-1].tat;
                    x[k].tat = x[k].wt + qt;
                    p[i].rbt -= qt;

                    cmp = x[k].tat;
                    k++
                }
            }
        }
    }
}