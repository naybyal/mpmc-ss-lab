#include<stdio.h>

struct process {
	int bt, tat, wt, id, rbt;
} p[40], x[40];


void main() {
	int i,j, qt,cmp=0, netBurst=0,n;
	int totalTAT=0, totalWT=0;

	printf("Reading the number of processes... ");
	scanf("%d", &n);

	printf("Reading the burst time of each process... \n");
	for (i=0;i<n;i++) {
		p[i].id = i+1;
		printf("PROCESS %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;

		netBurst += p[i].bt;
	}

	printf("Reading time slice... ");
	scanf("%d", &qt);
	int k=1;
	x[0].tat = 0;
	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt!=0) {
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
				} else {
					x[k].wt = x[k-1].tat;
					x[k].tat = x[k].wt + qt;
					p[i].rbt -= qt;

					cmp = x[k].tat;
					k++;
				}	
			}
		}
	}

	printf("\nPROCESS\tWT\tTAT\tBT\n");
	for (i=0; i<n; i++) {
		printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].tat, p[i].bt);
	}
	printf("\n");

	float avgTAT = (float)totalTAT/n;
	float avgWT = (float)totalWT/n;


	printf("\nAverage TAT : %.1f\n", avgTAT);
	printf("Average WT : %.1f", avgWT);

	printf("----GANTT CHART")
}
