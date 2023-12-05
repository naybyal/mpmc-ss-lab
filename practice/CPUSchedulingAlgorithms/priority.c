#include<stdio.h>

struct process {
	int id,bt, tat, wt, prio;
}p[50], temp;

void main() {
	int i,j, n;	
	printf("Reading the number of processes... ");
	scanf("%d", &n);
	
	printf("Reading the burst times and priority of each process....\n");
	for (i=0; i<n; i++) {
		printf("----PROCESS %d----\n", i+1);
		printf("Burst time\t->\t");
		scanf("%d", &p[i].bt);
		printf("Priority\t->\t");
		scanf("%d", &p[i].prio);
		p[i].id = i+1;
	}

	//	sorting the processes by priority
	
	for (i=0; i<n; i++) {
		for (j=0; j<n-i-1; j++) {
			if (p[j].prio < p[j+1].prio) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	p[0].wt = 0;
	p[0].tat = p[0].bt;
	int totalTAT=0, totalWT=0;
	float avgTAT, avgWT;
	
	// computing wt for each process...
	for (i=1;i<n;i++) {
		p[i].wt = p[i-1].bt+p[i-1].wt;
		totalWT += p[i].wt;
	}

	for (i=0;i<n;i++) {
		p[i].tat = p[i].bt + p[i].wt;
		totalTAT += p[i].tat;
	}


	printf("\tPROCESS\tWT\tBT\tTAT\tPRIO\n");
	for (i=0; i<n; i++) {
		printf("\tP%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].bt, p[i].tat, p[i].prio);
	}

	printf("\n\n\n");
	avgTAT = (float)totalTAT/n;
	printf("Average TAT\t->\t%.1f\n", avgTAT);

	avgWT = (float)totalWT/n;
	printf("Average WT\t->\t%.1f\n\n", avgWT);
}
